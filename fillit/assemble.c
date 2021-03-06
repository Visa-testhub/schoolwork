/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:09:35 by vkeinane          #+#    #+#             */
/*   Updated: 2020/01/09 12:28:44 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**FOR LOOKING IF THE CURRENT GRID HAS EMPTY PLACES TO FIT THE BLOCK INTO
*/

static unsigned long	empty_place(unsigned long temp, t_values *v)
{
	while ((temp & v->grid) || (temp & v->mask))
	{
		temp >>= 1;
		if (temp & 1)
			return (0);
	}
	return (temp);
}

/*
** FOR MOVING THE GRID DOWNWARD IF THE BLOCK DOESNT FIT IN CURRENG GRID
*/

static int				rows_downward(t_values *v, int j, unsigned long *temp)
{
	while (!(empty_place(*temp, v)) && *temp)
	{
		if (!(v->line_index & v->mask))
		{
			grid_to_map(v, j);
			v->line_index >>= 1;
			j++;
			while (!(*temp & 0x8000800080008000))
				*temp <<= 1;
			while (!(*temp & 0xF000000000000000))
				*temp <<= 16;
		}
		else
			*temp = 0;
		map_to_grid(v, j);
	}
	return (j);
}

/*
** This function eiher saves the current block by adding its information
** to the map.
** Or removes the block from the map if the rest of the blocks didn't fit
** in to the grid.
*/

static void				remove_or_save_block(t_values *v, int *j,
											unsigned long *temp, int i)
{
	int	k;

	k = 0;
	if (i == 0)
	{
		map_to_grid(v, *j);
		v->grid = *temp ^ v->grid;
		grid_to_map(v, *j);
		*temp >>= 1;
		v->line_index = 0x800000000000000;
		while (k != *j)
		{
			v->line_index >>= 1;
			k++;
		}
	}
	else
	{
		v->grid = *temp | v->grid;
		grid_to_map(v, *j);
		map_to_grid(v, 0);
	}
}

/*
** The recursive function testing all the blocks to the grid
** to see if they fit.
*/

static unsigned long	block_to_grid(t_block *blocks, t_values *v, int i)
{
	unsigned long	temp;
	int				j;

	v->line_index = 0x800000000000000;
	v->success = 0;
	j = 0;
	temp = blocks[i].block;
	while (temp && !v->success)
	{
		j = rows_downward(v, j, &temp);
		temp = empty_place(temp, v);
		if (temp)
		{
			remove_or_save_block(v, &j, &temp, 1);
			if (!(v->success = block_to_grid(blocks, v, i + 1)))
				remove_or_save_block(v, &j, &temp, 0);
			else
				save_info(blocks, temp, j, i);
		}
		else
			return (0);
	}
	return ((!i && !v->grid) ? 0 : 1);
}

void					assemble(t_block *blocks)
{
	int				i;
	t_values		v;

	i = -1;
	mapsize(blocks, &v);
	v.grid = 0;
	while (++i < 16)
		v.map[i] = 0;
	while (!block_to_grid(blocks, &v, 0))
	{
		if (!v.grid)
			grow_mask(&v);
	}
	i = 0;
	v.grid = 0x8000000000000000;
	while (!(v.grid & v.mask))
	{
		v.grid >>= 1;
		i++;
	}
	grow_mask(&v);
	make_square(blocks, i, v.mask);
}
