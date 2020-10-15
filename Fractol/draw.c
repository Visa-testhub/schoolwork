/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:18:39 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/06 11:48:55 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_frctl *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_lenght + x * (f->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	put_line_julia(t_frctl *f, t_draw d)
{
	d.newr = 1.5 * (d.x - d.w / 2) / (0.5 * f->zoom * d.w) + f->movex;
	d.newi = (d.y - d.hmax / 2) / (0.5 * f->zoom * d.hmax) + f->movey;
	while (d.i < f->maxiterations)
	{
		d.oldr = d.newr;
		d.oldi = d.newi;
		d.newr = (d.oldr * d.oldr) - (d.oldi * d.oldi) + f->cr;
		d.newi = 2 * d.oldr * d.oldi + f->ci;
		if ((d.newr * d.newr + d.newi * d.newi) > 4)
			break ;
		d.i++;
	}
	d.color = colorpicker(d.i, f);
	if (d.i == f->maxiterations)
		d.color = 0;
	my_mlx_pixel_put(f, d.x, d.y, d.color);
}

static void	put_line_burning_ship(t_frctl *f, t_draw d)
{
	d.pr = 1.5 * (d.x - d.w / 2) / (0.5 * f->zoom * d.w) + f->movex;
	d.pi = (d.y - d.hmax / 2) / (0.5 * f->zoom * d.hmax) + f->movey;
	d.newr = 0;
	d.newi = 0;
	d.oldr = 0;
	d.oldi = 0;
	while (d.i < f->maxiterations)
	{
		d.oldr = fabs(d.newr);
		d.oldi = fabs(d.newi);
		d.newr = d.oldr * d.oldr - d.oldi * d.oldi + d.pr;
		d.newi = 2 * d.oldr * d.oldi + d.pi;
		if ((d.newr * d.newr + d.newi * d.newi) > 4)
			break ;
		d.i++;
	}
	d.color = colorpicker(d.i, f);
	if (d.i == f->maxiterations)
		d.color = 0;
	my_mlx_pixel_put(f, d.x, d.y, d.color);
}

static void	put_line_mandelbrot(t_frctl *f, t_draw d)
{
	d.pr = 1.5 * (d.x - d.w / 2) / (0.5 * f->zoom * d.w) + f->movex;
	d.pi = (d.y - d.hmax / 2) / (0.5 * f->zoom * d.hmax) + f->movey;
	d.newr = 0;
	d.newi = 0;
	d.oldr = 0;
	d.oldi = 0;
	while (d.i < f->maxiterations)
	{
		d.oldr = d.newr;
		d.oldi = d.newi;
		d.newr = d.oldr * d.oldr - d.oldi * d.oldi + d.pr;
		d.newi = 2 * d.oldr * d.oldi + d.pi;
		if ((d.newr * d.newr + d.newi * d.newi) > 4)
			break ;
		d.i++;
	}
	d.color = colorpicker(d.i, f);
	if (d.i == f->maxiterations)
		d.color = 0;
	my_mlx_pixel_put(f, d.x, d.y, d.color);
}

void		draw_fractal(t_frctl *f)
{
	t_draw	d;

	get_thread(f, &d);
	d.w = WIN_WIDHT - 1;
	d.hmax = WIN_HEIGHT - 1;
	d.x = 0;
	d.i = 0;
	while (d.y < d.h)
	{
		while (d.x < d.w)
		{
			if (f->fractaltype == 2)
				put_line_mandelbrot(f, d);
			else if (f->fractaltype == 1)
				put_line_julia(f, d);
			else
				put_line_burning_ship(f, d);
			d.x++;
		}
		d.x = 0;
		d.y++;
	}
}
