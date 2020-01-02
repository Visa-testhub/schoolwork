/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:09:35 by vkeinane          #+#    #+#             */
/*   Updated: 2020/01/02 18:07:53 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**FOR TRANSFERRING CURRENT GRID TO THE MAP WITCH KEEPS THE WHOLE SQUARE
*/
void			grid_to_map(t_values *v, int start)
{
	v->map[start + 3] = v->grid & 0xFFFF;
	v->map[start + 2] = (v->grid >> 16) & 0xFFFF;
	v->map[start + 1] = (v->grid >> 32) & 0xFFFF;
	v->map[start + 0] = (v->grid >> 48) & 0xFFFF;
}

/*
**FOR TRANSFERRING FROM MAP TO THE GRID IN USE AT THE MOMENT
*/
void			map_to_grid(t_values *v, int start)
{
	v->grid = 0;
	v->grid = v->map[start];
	v->grid <<= 16;
	v->grid = v->grid | v->map[start + 1];
	v->grid <<= 16;
	v->grid = v->grid | v->map[start + 2];
	v->grid <<= 16;
	v->grid = v->grid | v->map[start + 3];
}

/*FOR GROWING THE MAP SIZE IF THE BLOCKS DO NOT FIT IN CURRENT MAP*/
void			grow_mask(t_values *v)
{
	if (v->mask == mask2)
		v->mask = mask3;
	else if (v->mask == mask3)
		v->mask = mask4;
	else
	{
		v->mask >>= 1;
		v->mask = v->mask & mask4;
	}
}

/*
**FOR TESTING THE MINIMUM SIZE MAP NEEDED FOR THE BLOCK FITTING
*/
void			mapsize(t_block *blocks, t_values *v)
{
	int	i;

	i = 0;
	while (blocks[i].type != '\0')
		i++;
	if (i == 1)
		v->mask = mask2;
	else if (i == 2)
		v->mask = mask3;
	else if (i == 3 || i == 4)
		v->mask = mask4;
	else if (i == 5 || i == 6)
		v->mask = mask5;
	else if (i >= 7 && i <= 9)
		v->mask = mask6;
	else if (i >= 10 && i <= 12)
		v->mask = mask7;
	else if (i >= 13 && i <= 16)
		v->mask = mask8;
	else if (i >= 17 && i <= 20)
		v->mask = mask9;
	else if (i >= 21 && i <= 25)
		v->mask = mask10;
	else
		v->mask = mask11;
}

/*
**FOR LOOKING IF THE CURRENT GRID HAS EMPTY PLACES TO FIT THE BLOCK INTO
*/
unsigned long	empty_place(unsigned long temp, t_values *v)
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
int				rows_downward(t_values *v, int j, unsigned long *temp)
{
	while (!(empty_place(*temp, v)) && *temp)
	{
		if (!(v->line_index & v->mask))
		{
			grid_to_map(v, j);
			v->line_index >>= 1;
			j++;
		}
		else
			*temp = 0;
		map_to_grid(v, j);
	}
	return (j);
}


/*
**FOR TESTING IF THE TETRIMINOS FIT TO THE CURRENT SIZE OF MAP
*/
unsigned long	block_to_grid(t_block *blocks, t_values *v, int i)
{
	unsigned long	temp;
	unsigned long	tempgrid;
	int	j;

	v->line_index = 0x800000000000000;
	v->success = 0;
	j = 0;
	temp = blocks[i].block;
	while (temp && !v->success)
	{
		if (v->mask < mask4)
			j = rows_downward(v, j, &temp);
		temp = empty_place(temp, v);
		if (temp)
		{
			v->grid = temp | v->grid;
			tempgrid = v->grid;
			grid_to_map(v, j);
			map_to_grid(v, 0);
			if (!(v->success = block_to_grid(blocks, v, i + 1)))
			{
				v->grid = tempgrid;
				v->grid = temp ^ v->grid;
				grid_to_map(v, j);
				temp >>= 1;
			}
			else
			{
				blocks[i].block = temp;
				blocks[i].row = j;
			}
		}
		else
			return (0);
	}
	if (!i && !v->grid)
		return (0);
	return (1);
}

void	assemble(t_block *blocks)
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
	grow_mask(&v);	make_square(blocks, i, v.mask);
}

/*>>>>>>>>>>>WORKS FINE, ONE TOO LONG FUNCTION<<<<<<<<<<<<<*/
/*
unsigned long	block_to_grid(t_block *blocks, t_values *v, int i)
{
	unsigned long	temp;
	unsigned long	tempgrid;
	int	j;

	v->line_index = 0x800000000000000;
	v->success = 0;
	j = 0;
	temp = blocks[i].block;
	while (temp && !v->success)
	{
		if (v->mask < mask4)
			j = rows_downward(v, j, &temp);
		temp = empty_place(temp, v);
		if (temp)
		{
			v->grid = temp | v->grid;
			tempgrid = v->grid;
			grid_to_map(v, j);
			map_to_grid(v, 0);
			if (!(v->success = block_to_grid(blocks, v, i + 1)))
			{
				v->grid = tempgrid;
				v->grid = temp ^ v->grid;
				grid_to_map(v, j);
				temp >>= 1;
			}
			else
			{
				blocks[i].block = temp;
				blocks[i].row = j;
			}
		}
		else
			return (0);
	}
	if (!i && !v->grid)
		return (0);
	return (1);
}
*/

/* FIRST VERSION>>>>>>>>>>>>>>>>>>>>> THIS WORKS ONLY ON 4 ROWS<<<<<<<<<<<<<<<<<<<<<<<<*/
/*
unsigned long	block_to_grid(unsigned long *grid, t_block *blocks, unsigned long mask, int i)
  {
  unsigned long temp;
  unsigned int succed = 0;

  temp = blocks[i].block;
  while (temp && !succed)
  {
	  temp = empty_place(*grid, mask, temp);
	  if (temp)
	  {
		  *grid = temp | *grid;
		  if (!(succed = block_to_grid(grid, blocks, mask, i + 1)))
		  {
			  *grid = temp ^ *grid;
			  temp >>= 1;
		  }
	  }
	  else
		  return (0);
  }
  if (!i && !*grid)
	  return (0);
  return (1);
}
*/
