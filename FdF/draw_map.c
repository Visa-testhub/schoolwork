/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:18:21 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/27 09:45:20 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_cord start, t_cord end, int dist, int maxdist)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = 20;
	g = 50 + (start.z * 3);
	b = 50 + (start.z * 3);
	if (end.z > start.z)
	{
		g = g + (maxdist - dist);
		b = b + (maxdist - dist);
	}
	else if (end.z < start.z)
	{
		g = g + dist;
		b = b + dist;
	}
	else if (end.z == start.z && start.z >= 5)
	{
		g = g + maxdist;
		b = b + maxdist;
	}
	return (r << 16 | g << 8 | b);
}

void	draw_perspective_map(t_fdf *fdf)
{
	t_cord	cur;
	t_cord	next;
	t_cord	start;
	int		y;
	int		x;

	y = 0;
	x = 0;
	start.x = (fdf->height * (fdf->gap)) + fdf->left_right + 20;
	start.y = 60 - (fdf->z[y][x] * fdf->alt_mult) + fdf->up_down;
	while (y < fdf->height)
	{
		cur.x = start.x;
		cur.y = start.y;
		next_point_perspective(fdf, &cur, &next, y);
		x = 0;
		start.x = start.x - (fdf->gap);
		if ((y + 1) < fdf->height)
			start.y = (start.y + fdf->gap) - ((fdf->z[y + 1][x] * \
						fdf->alt_mult) - (fdf->z[y][x] * fdf->alt_mult) - (y));
		y++;
	}
}

void	draw_cabinet_map(t_fdf *fdf)
{
	t_cord	cur;
	t_cord	next;
	t_cord	start;
	int		y;
	int		x;

	y = 0;
	x = 0;
	start.x = (fdf->height * (fdf->gap)) + fdf->left_right + 20;
	start.y = 60 - (fdf->z[y][x] * fdf->alt_mult) + fdf->up_down;
	while (y < fdf->height)
	{
		cur.x = start.x;
		cur.y = start.y;
		next_point_cabinet(fdf, &cur, &next, y);
		x = 0;
		start.x = start.x - (fdf->gap);
		if ((y + 1) < fdf->height)
			start.y = (start.y + fdf->gap) - ((fdf->z[y + 1][x] * \
						fdf->alt_mult) - (fdf->z[y][x] * fdf->alt_mult));
		y++;
	}
}

void	draw_isometric_map(t_fdf *fdf)
{
	t_cord	cur;
	t_cord	next;
	t_cord	start;
	int		y;
	int		x;

	y = 0;
	x = 0;
	start.x = (fdf->height * (fdf->gap * 2)) + fdf->left_right;
	start.y = 20 - (fdf->z[y][x] * fdf->alt_mult) + fdf->up_down;
	while (y < fdf->height)
	{
		cur.x = start.x;
		cur.y = start.y;
		next_point_isometric(fdf, &cur, &next, y);
		x = 0;
		start.x = start.x - (fdf->gap * 2);
		if ((y + 1) < fdf->height)
			start.y = (start.y + fdf->gap) - ((fdf->z[y + 1][x] * \
						fdf->alt_mult) - (fdf->z[y][x] * fdf->alt_mult));
		y++;
	}
}
