/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:50:29 by vkeinane          #+#    #+#             */
/*   Updated: 2019/12/13 14:01:52 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	validate_shape(t_block blocks)
{
	if (blocks.block == UP_L || blocks.block == LEFT_L)
		return ;
	if (blocks.block == DOWN_L || blocks.block == RIGHT_L)
		return ;
	if (blocks.block == UP_J || blocks.block == LEFT_J)
		return ;
	if (blocks.block == DOWN_J || blocks.block == RIGHT_J)
		return ;
	if (blocks.block == UP_T || blocks.block == LEFT_T)
		return ;
	if (blocks.block == DOWN_T || blocks.block == RIGHT_T)
		return ;
	if (blocks.block == HORIZONTAL_S || blocks.block == VERTICAL_S)
		return ;
	if (blocks.block == HORIZONTAL_Z || blocks.block == VERTICAL_Z)
		return ;
	if (blocks.block == HORIZONTAL_LINE || blocks.block == VERTICAL_LINE)
		return ;
	if (blocks.block == SQUARE)
		return ;
	usage_and_exit(2);
}

void	make_shape(char *buf, t_block *blocks)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			blocks->block <<= 1;
			blocks->block += 1;
		}
		else if (buf[i] == '.')
		{
			blocks->block <<= 1;
			blocks->block += 0;
		}
		if (buf[i] == '\n' && i < 20)
			blocks->block <<= 12;
		i++;
	}
	while (!(blocks->block & 0x8000800080008000))
		blocks->block <<= 1;
	while (!(blocks->block & 0xF000000000000000))
		blocks->block <<= 16;
}

void	validate_chars(char *buf, int ret)
{
	int	hash;
	int dot;
	int nline;
	int i;

	i = 0;
	hash = 0;
	dot = 0;
	nline = 0;
	if (ret == 20)
		buf[20] = '\n';
	while (buf[i])
	{
		if ((i == 4 || i == 9 || i == 14 || i == 19) && buf[i] != '\n')
			usage_and_exit(2);
		buf[i] == '#' ? hash++ : hash;
		buf[i] == '.' ? dot++ : dot;
		buf[i] == '\n' ? nline++ : nline;
		i++;
	}
	if (hash != 4 || dot != 12 || nline != 5)
		usage_and_exit(2);
}

void	validate(t_block *blocks, int fd)
{
	char	buf[22];
	char	letter;
	int		ret;
	int		i;

	i = 0;
	letter = 'A';
	while (ret = read(fd, buf, 21))
	{
		buf[21] = '\0';
		if ((ret > 0 && ret < 20) || ret < 0)
			usage_and_exit(2);
		validate_chars(buf, ret);
		make_shape(buf, &blocks[i]);
		validate_shape(blocks[i]);
		blocks[i].type = letter++;
		if (i++ > 25)
			usage_and_exit(2);
	}
	while (++i <= 26)
	{
		blocks[i].type = '\0';
		blocks[i].block = 0;
	}
}
