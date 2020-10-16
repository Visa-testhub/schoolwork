/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:06:49 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/24 10:52:42 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_textures(t_wolf *s, t_ray *v, t_ray *h)
{
	if (v->dir == 0 || (s->raylen_h <= s->raylen_v && h->dir != 0))
	{
		if (h->dir == 1 || h->dir == 2)
			s->tex->x = h->mapoffx;
		else
			s->tex->x = 0;
		if (h->dir == 1)
			s->tex->x += MAP_OFFSET;
		s->walltype[2] = s->walltype[0];
	}
	else
	{
		if (v->dir == 1 || v->dir == 2)
			s->tex->x = v->mapoffy;
		else
			s->tex->x = 0;
		if (v->dir == 1)
			s->tex->x += (MAP_OFFSET * 2);
		if (v->dir == 2)
			s->tex->x += (MAP_OFFSET * 3);
		s->walltype[2] = s->walltype[1];
	}
}

static void		ray_hitlenght(t_wolf *s, t_ray *v, t_ray *h)
{
	double	dist_y;
	double	dist_x;

	dist_x = (s->player->x - v->x) * (s->player->x - v->x);
	dist_y = (s->player->y - v->y) * (s->player->y - v->y);
	s->raylen_v = sqrt(dist_x + dist_y);
	dist_x = (s->player->x - h->x) * (s->player->x - h->x);
	dist_y = (s->player->y - h->y) * (s->player->y - h->y);
	s->raylen_h = sqrt(dist_x + dist_y);
	if (v->dir == 0 || (s->raylen_h <= s->raylen_v && h->dir != 0))
		s->dist = s->raylen_h;
	else
		s->dist = s->raylen_v;
	s->dist = s->dist * cos(v->angle - s->pangle);
}

static float	check_angle(float angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void			cast_rays(t_wolf *s)
{
	t_ray	h;
	t_ray	v;
	int		raynb;

	raynb = -1;
	h.angle = s->pangle - ((FOV / 2) * DEGREE);
	h.angle = check_angle(h.angle);
	v.angle = h.angle;
	while (++raynb < RAY_AMOUNT)
	{
		h.dof = 0;
		v.dof = 0;
		h.tan = -1 / tan(h.angle);
		v.tan = -tan(v.angle);
		stepdist_vertical(s, &v);
		stepdist_horizontal(s, &h);
		ray_endpoint(s, &h, 0);
		ray_endpoint(s, &v, 1);
		ray_hitlenght(s, &v, &h);
		set_textures(s, &v, &h);
		draw_slice(raynb, s, v.angle);
		h.angle += (DEGREE / 18);
		h.angle = check_angle(h.angle);
		v.angle = h.angle;
	}
}
