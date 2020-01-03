/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:00:33 by vkeinane          #+#    #+#             */
/*   Updated: 2020/01/03 19:37:18 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_to_grid(t_values *v, int start)
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

void	grid_to_map(t_values *v, int start)
{
	v->map[start + 3] = v->grid & 0xFFFF;
	v->map[start + 2] = (v->grid >> 16) & 0xFFFF;
	v->map[start + 1] = (v->grid >> 32) & 0xFFFF;
	v->map[start + 0] = (v->grid >> 48) & 0xFFFF;
}

void	grow_mask(t_values *v)
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

void	mapsize(t_block *blocks, t_values *v)
{
	int i;

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

void	save_info(t_block *blocks, unsigned long temp, int j, int i)
{
	blocks[i].block = temp;
	blocks[i].row = j;
}
