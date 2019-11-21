/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:50:29 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/21 18:03:10 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void	validate_first(char *buf)
{
	int	hash;
	int dot;
	int nline;
	int i;
	int a;

	a = 0;
	i = 0;
	hash = 0;
	dot = 0;
	nline = 0;
	while (buf[i])
	{
		if (buf[i] == '#' && i < 15)
		{
			if (buf[i + 1] == '#' || buf[i + 5] == '#')
				a++;
			else if (buf[i - 1] == '#' && buf[i + 4] == '#')
				a++;
		}
		buf[i] == '#' ? hash++ : hash;
		buf[i] == '.' ? dot++ : dot;
		buf[i] == '\n' ? nline++ : nline;
		i++;
	}
	if (hash != 4 || dot != 12 || nline != 5 || a != 3)
		usage_and_exit(2);
}
/*
char	*validate(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			if (buf[i + 1] == '#' || buf[i - 1] == '#')
		i++;
	}
}
*/
int		validator(int fd)
{
	char static	tetriminos[19][22];
	char		buf[22];
	int			ret;
	int			i;

	i = -1;
	while ((ret = read(fd, buf, 21)) && i++ <= 19)
	{
		buf[21] = '\0';
//		printf("%s\n", buf);
//		printf("%d\n", ret);
		if (ret > 0 && ret < 21)
			usage_and_exit(2);
		validate_first(buf);
		
	}
	close(fd);
	return (0);
}
