/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:20:07 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/22 18:53:29 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		**map_space(t_read *r)
{
	int		**map;
	int		y;

	y = 0;
	if (!(map = (int **)malloc(r->height * sizeof(int *))))
		shutdown(5);
	while (y < r->height)
	{
		if (!(map[y] = (int *)malloc(r->widht * sizeof(int))))
			shutdown(5);
		y++;
	}
	return (map);
}

int		assemble_map(int fd, t_wolf *s, t_read *r)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	x = -1;
	line = NULL;
	while ((r->ret = get_next_line(fd, &line)))
	{
		if (r->ret < 0)
			return (1);
		while (line[++x])
			s->map[y][x] = (line[x] - '0');
		x = -1;
		y++;
		free(line);
	}
	return (0);
}

void	file_read(char *filename, t_wolf *s)
{
	t_read	r;
	int		fd;

	if (((fd = open(filename, O_RDONLY)) == -1))
		shutdown(3);
	if (validate(fd, &r, s))
		shutdown(3);
	if (close(fd))
		shutdown(9);
	s->map = map_space(&r);
	if ((fd = open(filename, O_RDONLY)) == -1)
		shutdown(3);
	if (assemble_map(fd, s, &r))
		shutdown(4);
	s->widht = r.widht;
	s->height = r.height;
	if (close(fd))
		shutdown(9);
}
