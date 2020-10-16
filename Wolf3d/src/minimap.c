/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:39:20 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/22 20:56:09 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_minimap	*init_minimap(void)
{
	t_minimap	*m;

	if (!(m = (t_minimap *)malloc(sizeof(t_minimap))))
		shutdown(5);
	if (!(m->curr = (t_cord *)malloc(sizeof(t_cord))) || \
			!(m->start = (t_cord *)malloc(sizeof(t_cord))) || \
			!(m->end = (t_cord *)malloc(sizeof(t_cord))) || \
			!(m->sq_s = (t_cord *)malloc(sizeof(t_cord))) || \
			!(m->sq_e = (t_cord *)malloc(sizeof(t_cord))) || \
			!(m->p = (t_cord *)malloc(sizeof(t_cord))))
		shutdown(5);
	m->curr->x = 0;
	m->curr->y = 0;
	m->start->x = 0;
	m->start->y = 0;
	m->end->x = 0;
	m->end->y = 0;
	m->sq_s->x = 0;
	m->sq_s->y = 0;
	m->sq_e->x = 0;
	m->sq_e->y = 0;
	m->p->x = 0;
	m->p->y = 0;
	return (m);
}

static void	draw_point(t_minimap *m, t_wolf *s)
{
	m->sq_s->x = ((m->curr->x - m->start->x) * 4);
	m->sq_s->y = ((m->curr->y - m->start->y) * 4);
	m->sq_e->x = ((m->curr->x - m->start->x) * 4) + 4;
	m->sq_e->y = ((m->curr->y - m->start->y) * 4) + 4;
	while (m->sq_s->y < (m->sq_e->y - 1))
	{
		while (m->sq_s->x < (m->sq_e->x - 1))
		{
			if (m->sq_s->x < WIN_WIDHT && m->sq_s->y < WIN_HEIGHT)
			{
				if (m->curr->x == m->p->x && m->curr->y == m->p->y)
					pixel_to_img(s, m->sq_s->x, m->sq_s->y, 0xAAFFAA);
				else
					pixel_to_img(s, m->sq_s->x, m->sq_s->y, MINIMAP_COLOR);
			}
			m->sq_s->x++;
		}
		m->sq_s->x = ((m->curr->x - m->start->x) * 4);
		m->sq_s->y++;
	}
}

static void	check_map_borders(t_minimap *m, t_wolf *s)
{
	while (m->curr->y < 0)
		m->curr->y++;
	while (m->curr->x < 0)
		m->curr->x++;
	while (m->end->y > s->height)
		m->end->y--;
	while (m->end->x > s->widht)
		m->end->x--;
}

void		draw_minimap(t_minimap *m, t_wolf *s)
{
	m->p->y = (s->player->y / MAP_OFFSET);
	m->p->x = (s->player->x / MAP_OFFSET);
	m->curr->y = (s->player->y / MAP_OFFSET) - 10;
	m->curr->x = (s->player->x / MAP_OFFSET) - 10;
	m->end->y = m->curr->y + 20;
	m->end->x = m->curr->x + 20;
	check_map_borders(m, s);
	m->start->x = m->curr->x;
	m->start->y = m->curr->y;
	while (m->curr->y < m->end->y)
	{
		while (m->curr->x < m->end->x)
		{
			if (s->map[m->curr->y][m->curr->x] == 1 || \
				(m->curr->x == m->p->x && m->curr->y == m->p->y))
				draw_point(m, s);
			m->curr->x++;
		}
		m->curr->x = m->start->x;
		m->curr->y++;
	}
}
