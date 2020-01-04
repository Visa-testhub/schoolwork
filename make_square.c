/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:35:59 by vkeinane          #+#    #+#             */
/*   Updated: 2019/12/13 13:55:57 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_space(char **square, int i)
{
	int	j;
	int	k;

	if (!(square = (char **)malloc((i + 1) * sizeof(char *))))
		usage_and_exit(2);
	square[i] = NULL;
	j = -1;
	k = 0;
	while (++j < i)
	{
		if (!(square[j] = (char *)malloc((i + 1) * sizeof(char))))
			usage_and_exit(2);
		square[j][i] = '\0';
		while (k < i)
		{
			square[j][k] = '.';
			k++;
		}
		k = 0;
	}
	return (square);
}

char	**fill_square(char **square, t_block blocks, unsigned long mask)
{
	unsigned long	flag;
	int				i;
	int				j;

	i = blocks.row;
	j = 0;
	flag = 0x8000000000000000;
	while (!(flag & 1))
	{
		if (flag & mask)
			i++;
		while (flag & mask)
		{
			if (flag & 1)
				return (square);
			flag >>= 1;
			j = 0;
		}
		if (blocks.block & flag)
			square[i][j] = blocks.type;
		flag >>= 1;
		j++;
	}
	return (square);
}

void	delete_square(char **square)
{
	int	i;

	i = 0;
	while (square[i])
	{
		free(square[i]);
		i++;		
	}
}

void	make_square(t_block *blocks, int i, unsigned long mask)
{
	char	**square;
	int		j;

	square = NULL;
	square = make_space(square, i);
	i = -1;
	while (blocks[++i].type)
		square = fill_square(square, blocks[i], mask);
	i = 0;
	j = 0;
	while (square[j] != NULL)
	{
		while (square[j][i] != '\0')
			i++;
		write(1, square[j], i);
		write(1, "\n", 1);
		i = 0;
		j++;
	}
	delete_square(square);
}
/*
** PREVIUS VERSION OF PUTTING THE BLOCKS INT THE SQUARE
**char	**fill_square(char **square, t_block *blocks, unsigned long mask, int i)
**{
**	unsigned long	flag;
**	int				j;
**	int				k;
**
**	j = 0;
**	k = blocks[i].row;
**	flag = 0x8000000000000000;
**	while (blocks[i].type)
**	{
**		if (flag & mask)
**			k++;
**		while (flag & mask)
**		{
**			if (flag & 1)
**			{
**				flag = 0x8000000000000000;
**				i++;
**				k = blocks[i].row;
**				j = 0;
**				break ;
**			}
**			flag >>= 1;
**			j = 0;
**		}
**		if (blocks[i].block & flag)
**
**			square[k][j] = blocks[i].type;
**		flag >>= 1;
**		j++;
**	}
**	return (square);
**}
*/
