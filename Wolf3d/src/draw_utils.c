/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:16:38 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/23 14:12:14 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		pixel_to_img(t_wolf *s, int x, int y, int color)
{
	char	*dst;

	dst = s->addr + (y * s->line_lenght + x * (s->bpp / 8));
	*(unsigned int*)dst = color;
}

void		draw_compass(t_wolf *s)
{
	t_cord	start;
	t_cord	end;

	start.x = 1030;
	start.y = 50;
	end.x = start.x + s->delta->x * 5;
	end.y = start.y + s->delta->y * 5;
	draw_line(start, end, *s);
	pixel_to_img(s, end.x - 1, end.y, 0xFFFFFF);
	pixel_to_img(s, end.x, end.y - 1, 0xFFFFFF);
	pixel_to_img(s, end.x + 1, end.y, 0xFFFFFF);
	pixel_to_img(s, end.x, end.y + 1, 0xFFFFFF);
}

static void	init_line(t_line *l, t_cord *s, t_cord *e)
{
	l->len_x = e->x - s->x;
	l->len_y = e->y - s->y;
	l->dx1 = (l->len_x < 0) ? -1 : 0;
	l->dx2 = (l->len_x < 0) ? -1 : 0;
	l->dx1 = (l->len_x > 0) ? 1 : l->dx1;
	l->dx2 = (l->len_x > 0) ? 1 : l->dx2;
	l->dy1 = (l->len_y < 0) ? -1 : 0;
	l->dy1 = (l->len_y > 0) ? 1 : l->dy1;
	l->dy2 = 0;
	l->longer = ft_abs(l->len_x);
	l->shorter = ft_abs(l->len_y);
	if (!(l->longer > l->shorter))
	{
		l->longer = ft_abs(l->len_y);
		l->shorter = ft_abs(l->len_x);
		if (l->len_y < 0)
			l->dy2 = -1;
		else if (l->len_y > 0)
			l->dy2 = 1;
		l->dx2 = 0;
	}
	l->calc = l->longer >> 1;
	l->count = 0;
}

void		draw_line(t_cord s, t_cord e, t_wolf st)
{
	t_line	l;

	init_line(&l, &s, &e);
	while (l.count <= l.longer)
	{
		if (!(s.x > WIN_WIDHT - 1) && !(s.y > WIN_HEIGHT - 1) && \
				!(s.x < 0) && !(s.y < 0))
		{
			pixel_to_img(&st, s.x, s.y, 0xFFFFFF);
		}
		l.calc += l.shorter;
		if (!(l.calc < l.longer))
		{
			l.calc -= l.longer;
			s.x += l.dx1;
			s.y += l.dy1;
		}
		else
		{
			s.x += l.dx2;
			s.y += l.dy2;
		}
		l.count++;
	}
}

void		draw_init(t_wolf *s)
{
	s->camera_dist = (WIN_WIDHT / 2) / tan((FOV / 2) * M_PI / 180);
	s->color = 0xFFFFF;
	s->pangle = 0.1 + M_PI / 2;
	s->walltype[0] = 0;
	s->walltype[1] = 0;
	s->walltype[2] = 0;
	s->toggle_compass = 1;
	s->toggle_minimap = 1;
	s->toggle_sprint = 6;
	s->toggle_help = 1;
	s->player->x = (s->player->x * MAP_OFFSET) + (MAP_OFFSET / 2);
	s->player->y = (s->player->y * MAP_OFFSET) + (MAP_OFFSET / 2);
	if (!(s->tex = (t_cord *)malloc(sizeof(t_cord))) || \
			!(s->delta = (t_cord_d *)malloc(sizeof(t_cord_d))))
		shutdown(5);
	deal_key(2, s);
}
