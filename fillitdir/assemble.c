/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:47:04 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/29 16:20:21 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*this funktion to transfer the current grid to list of shorts*/
t_map	long_to_short_array(unsigned long grid, int start)
{
	t_map	map;

	map.lines[start + 3] = grid & 0xFFFF;
	map.lines[start + 2] = (grid >> 16) & 0xFFFF;
	map.lines[start + 1] = (grid >> 32) & 0xFFFF;
	map.lines[start + 0] = (grid >> 48) & 0xFFFF;
	return (map);
}
/* to test needed starting grid depending on the number of blocks*/
unsigned long	gridsize(tblock *blocks)
{
	int		i;

	i = 0;
	while (blocks[i].type != '\0')
		i++;
	if (i == 1)
		return (mask2);
	if (i == 2)
		return (mask3);
	if (i == 3 || i == 4)
		return (mask4);
	if (i == 5 || i = 6)
		return (mask5);
	if (i >= 7 && i <= 9)
		return (mask6);
	if (i >= 10 && i <= 12)
		return (mask7);
	if (i >= 13 && i <= 16)
		return (mask8);
	if (i >= 17 && i <= 20)
		return (mask9);
	if (i >= 21 && i <= 25)
		return (mask10);
	if (i >= 26)
		return (mask11);
}
/*transgerring the block to grid. i thing in this way they dont store the cha
nges done to block while fitting it to the grid*/
unsigned long	block_to_grid(unsigned long grid, unsigned long block, unsigned long mask)
{
	while (block & grid)
	{
		block >>= 1;
		if (block & mask)/*diffrent masks here to test diff gridsizes*/
		{
			block >>= 15;
			/*sift diffrent amounts depending on the gridsize*/
		}
	}
	grid = grid | block;
	return (grid);
}

void	assemble(tblock *blocks)
{
	int 	i;
	t_map	map;
	unsigned long	grid;
	unsigned long	mask;

	i = 0;
	mask = gridsize(blocks);
	grid = 0;/*map.lines[0] | (map.lines[1] << 8) | (map.lines[2] << 16) | (map.lines[3] << 24);*/
				/*above in comment a way to change the map with four shorts to one long*/
	while (blocks[i].type != '\0')
	{
		/*some kind of gridsizetest*/
		if (/*grid too small*/)
			/*set grid and i to 0 and begin with diffrent gridsize*/
		grid = block_to_grid(grid, blocks[i].block, mask)
		i++;
	}
	map = long_to_short_array(grid, 0);
	printf("%lu", grid);
//	make_string(grid);
//	assemble(blocks);
}
