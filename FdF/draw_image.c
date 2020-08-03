/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:37:18 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/27 10:00:52 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_lenght + x * (fdf->bits_per_pix / 8));
	*(unsigned int*)dst = color;
}

void	next_point_isometric(t_fdf *fdf, t_cord *cur, t_cord *next, int y)
{
	int		x;

	x = -1;
	while (++x < fdf->widht)
	{
		cur->z = fdf->z[y][x];
		if ((y + 1) < fdf->height)
		{
			next->x = cur->x - (fdf->gap * 2);
			next->y = cur->y + fdf->gap - (fdf->z[y + 1][x] * fdf->alt_mult)\
						+ (fdf->z[y][x] * fdf->alt_mult);
			next->z = fdf->z[y + 1][x];
			draw_line(*cur, *next, *fdf);
		}
		if ((x + 1) < fdf->widht)
		{
			next->x = cur->x + (fdf->gap * 2);
			next->y = cur->y + fdf->gap - (fdf->z[y][x + 1] * fdf->alt_mult)\
						+ (fdf->z[y][x] * fdf->alt_mult);
			next->z = fdf->z[y][x + 1];
			draw_line(*cur, *next, *fdf);
		}
		cur->x = next->x;
		cur->y = next->y;
	}
}

void	next_point_cabinet(t_fdf *fdf, t_cord *cur, t_cord *next, int y)
{
	int		x;

	x = -1;
	while (++x < fdf->widht)
	{
		cur->z = fdf->z[y][x];
		if ((y + 1) < fdf->height)
		{
			next->x = cur->x - fdf->gap;
			next->y = cur->y + fdf->gap - (fdf->z[y + 1][x] * fdf->alt_mult)\
						+ (fdf->z[y][x] * fdf->alt_mult);
			next->z = fdf->z[y + 1][x];
			draw_line(*cur, *next, *fdf);
		}
		if ((x + 1) < fdf->widht)
		{
			next->x = cur->x + (fdf->gap * 2);
			next->y = cur->y - (fdf->z[y][x + 1] * fdf->alt_mult) +
				(fdf->z[y][x] * fdf->alt_mult);
			next->z = fdf->z[y][x + 1];
			draw_line(*cur, *next, *fdf);
		}
		cur->x = next->x;
		cur->y = next->y;
	}
}

void	next_point_perspective(t_fdf *fdf, t_cord *cur, t_cord *next, int y)
{
	int		x;

	x = -1;
	while (++x < fdf->widht)
	{
		cur->z = fdf->z[y][x];
		if ((y + 1) < fdf->height)
		{
			next->x = cur->x - fdf->gap + (x * 2);
			next->y = cur->y + fdf->gap - (fdf->z[y + 1][x] * fdf->alt_mult) +
				(fdf->z[y][x] * fdf->alt_mult + (y));
			next->z = fdf->z[y + 1][x];
			draw_line(*cur, *next, *fdf);
		}
		if ((x + 1) < fdf->widht)
		{
			next->x = cur->x + (fdf->gap * 2) + (y * 2);
			next->y = cur->y - (fdf->z[y][x + 1] * fdf->alt_mult) +
				(fdf->z[y][x] * fdf->alt_mult);
			next->z = fdf->z[y][x + 1];
			draw_line(*cur, *next, *fdf);
		}
		cur->x = next->x;
		cur->y = next->y;
	}
}
