/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 11:02:52 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/23 14:27:07 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		write_help_message(t_wolf *s)
{
	mlx_string_put(s->mlx, s->win, 10, 80, 0xFFFFFF, "\"help txt 'h'\"");
	mlx_string_put(s->mlx, s->win, 10, 91, 0xFFFFFF, "\"compass 'c'\"");
	mlx_string_put(s->mlx, s->win, 10, 102, 0xFFFFFF, "\"minimap 'm'\"");
	mlx_string_put(s->mlx, s->win, 10, 113, 0xFFFFFF, "\"sprint 'shift'\"");
	mlx_string_put(s->mlx, s->win, 10, 124, 0xFFFFFF, "\"to exit 'esc'\"");
}

void		draw_image(t_wolf *s)
{
	mlx_destroy_image(s->mlx, s->img);
	s->img = mlx_new_image(s->mlx, WIN_WIDHT, WIN_HEIGHT);
	s->addr = mlx_get_data_addr(s->img, &s->bpp, &s->line_lenght, &s->endian);
	cast_rays(s);
	if (s->toggle_compass)
		draw_compass(s);
	if (s->toggle_minimap)
		draw_minimap(s->mm, s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	if (s->toggle_compass)
	{
		mlx_string_put(s->mlx, s->win, 1025, 1, 0xFFFFFF, "N");
		mlx_string_put(s->mlx, s->win, 988, 38, 0xFFFFFF, "E");
		mlx_string_put(s->mlx, s->win, 1062, 38, 0xFFFFFF, "S");
		mlx_string_put(s->mlx, s->win, 1025, 75, 0xFFFFFF, "W");
	}
	if (s->toggle_help)
		write_help_message(s);
}

static int	darkening_effect(int color, int dist)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			precent;

	if (dist > 650)
		dist = 650;
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	precent = (float)dist / 650;
	r = r - (precent * r);
	g = g - (precent * g);
	b = b - (precent * b);
	return (r << 16 | g << 8 | b);
}

static void	set_draw_values(t_wolf *s, int *y, int *linestart, float *rayangle)
{
	*y = -1;
	s->line_h = (MAP_OFFSET / s->dist) * s->camera_dist;
	*linestart = (WIN_HEIGHT - s->line_h) / 2;
	*rayangle = *rayangle * (180 / M_PI);
	if (*rayangle > 180)
		*rayangle = 360 - *rayangle;
}

void		draw_slice(int raynb, t_wolf *s, float rayangle)
{
	float		percent;
	int			linestart;
	int			y;

	set_draw_values(s, &y, &linestart, &rayangle);
	while (++y < linestart && y < WIN_HEIGHT)
		pixel_to_img(s, raynb, y, (SKYCOLOR + (y >> 3) + rayangle));
	y = 0;
	while (y < s->line_h && (linestart + y) < WIN_HEIGHT)
	{
		if (linestart + y > 0)
		{
			percent = y / s->line_h;
			s->tex->y = percent * 32;
			s->color = s->texture[s->walltype[2]][s->tex->y][s->tex->x];
			s->color = darkening_effect(s->color, s->dist);
			pixel_to_img(s, raynb, (linestart + y), s->color);
		}
		y++;
	}
	while (linestart + y < WIN_HEIGHT)
		pixel_to_img(s, raynb, (linestart + y++), FLOORCOLOR);
}
