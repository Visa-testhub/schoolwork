/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:35:26 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/27 11:27:43 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int v)
{
	if (!(v))
		return (0);
	if (v < 0)
		v = v * -1;
	return (v);
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

void		draw_line(t_cord s, t_cord e, t_fdf fdf)
{
	t_line	l;

	init_line(&l, &s, &e);
	while (l.count <= l.longer)
	{
		fdf.color = get_color(s, e, (l.longer - l.count), l.longer);
		fdf.color = fdf.color_on == 0 ? 0xFFFFFF : fdf.color;
		if (!(s.x > WIN_WIDHT - 1) && !(s.y > WIN_HEIGHT - 1) && \
				!(s.x < 0) && !(s.y < 0))
			my_mlx_pixel_put(&fdf, s.x, s.y, fdf.color);
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

void		gap_init(t_fdf *fdf)
{
	fdf->gap = 500;
	fdf->grid_w = (fdf->height * (fdf->gap * 2)) + (fdf->widht *
					(fdf->gap * 2));
	fdf->grid_h = (fdf->height * fdf->gap) + (fdf->widht * fdf->gap);
	while (fdf->grid_h > (WIN_HEIGHT - 40) || fdf->grid_w > (WIN_WIDHT - 40))
	{
		if (fdf->gap <= 4)
			break ;
		if (fdf->grid_h > (WIN_HEIGHT * 2) || fdf->grid_w > (WIN_WIDHT * 2))
			fdf->gap = fdf->gap - 3;
		else
			fdf->gap--;
		fdf->grid_w = (fdf->height * (fdf->gap * 2)) + (fdf->widht *
						(fdf->gap * 2));
		fdf->grid_h = (fdf->height * fdf->gap) + (fdf->widht * fdf->gap);
	}
}

void		draw_init(t_fdf *fdf)
{
	fdf->alt_mult = 4;
	gap_init(fdf);
	fdf->up_down = 0;
	fdf->left_right = 0;
	fdf->projection = 0;
	fdf->color = START_COLOR;
	put_menu_top(fdf);
	put_menu_bottom(fdf);
	fdf->color_on = 0;
}
