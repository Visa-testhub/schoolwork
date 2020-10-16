/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:15:42 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/23 21:28:15 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_borders(char *l)
{
	int		i;

	i = 0;
	while (l[i])
	{
		if (l[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int		check_line(char *l, t_read *r, t_wolf *s)
{
	int		i;
	int		placex;

	placex = -1;
	i = 0;
	while (l[i])
	{
		placex++;
		if (!(l[i] == '0' || l[i] == '1' || l[i] == '2' || l[i] == '3'))
			return (1);
		if (l[i] == '2')
		{
			r->isplayer++;
			s->player->x = (double)placex;
			s->player->y = (double)r->height;
		}
		i++;
	}
	if (l[0] != '1' || l[r->widht - 1] != '1')
		return (1);
	return (0);
}

void	init_validate(t_read *r, t_wolf *s)
{
	r->isplayer = 0;
	r->height = 0;
	r->w_max = 0;
	r->w_min = MAX_INT;
	r->ret = 0;
	r->lastline = 0;
	r->firstline = 0;
	if (!(s->player = (t_cord_d *)malloc(sizeof(t_cord))))
		shutdown(5);
	s->player->x = 0;
	s->player->y = 0;
}

int		validate(int fd, t_read *r, t_wolf *s)
{
	char	*line;

	line = NULL;
	init_validate(r, s);
	while ((r->ret = get_next_line(fd, &line) != 0))
	{
		if (r->ret == -1)
			return (1);
		r->widht = ft_strlen(line);
		if (r->height == 0)
			r->firstline = check_borders(line);
		r->lastline = check_borders(line);
		r->w_max = r->widht > r->w_max ? r->widht : r->w_max;
		r->w_min = r->widht < r->w_min ? r->widht : r->w_min;
		if (check_line(line, r, s))
			return (1);
		free(line);
		r->height++;
	}
	if (r->lastline == 1 || r->firstline == 1 || r->w_min != r->w_max || \
			r->height < 4 || r->widht < 3 || r->isplayer != 1 || \
			r->height > 1000 || r->widht > 1000)
		return (1);
	return (0);
}
