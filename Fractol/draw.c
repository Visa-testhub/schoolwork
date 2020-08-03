/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:18:39 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/03 15:10:10 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	my_mlx_pixel_put(t_frctl *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_lenght + x * (f->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	put_line_julia(t_frctl *f, t_draw d)
{
	f->newr = 1.5 * (d.x - d.w / 2) / (0.5 * f->zoom * d.w) + f->movex;
	f->newi = (d.y - d.h / 2) / (0.5 * f->zoom * d.h) + f->movey;
	while (d.i < f->maxiterations)
	{
		f->oldr = f->newr;
		f->oldi = f->newi;
		f->newr = (f->oldr * f->oldr) - (f->oldi * f->oldi) + f->cr;
		f->newi = 2 * f->oldr * f->oldi + f->ci;
		if ((f->newr * f->newr + f->newi * f->newi) > 4)
			break ;
		d.i++;
	}
	f->color = colorpicker(d.i, f->maxiterations);
	if (d.i == f->maxiterations)
		f->color = 0;
	my_mlx_pixel_put(f, d.x, d.y, f->color);
}

/*void	draw_julia(t_frctl *f)
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		i;

	w = WIN_W - 1;
	h = WIN_H - 1;
	x = 0;
	y = 0;
	i = 0;
	while (y < h)
	{
		while (x < w)
		{
			put_line_julia(f, d);
			f->newr = 1.5 * (x - w / 2) / (0.5 * f->zoom * w) + f->movex;
			f->newi = (y - h / 2) / (0.5 * f->zoom * h) + f->movey;
			while (i < f->maxiterations)
			{
				f->oldr = f->newr;
				f->oldi = f->newi;
				f->newr = (f->oldr * f->oldr) - (f->oldi * f->oldi) + f->cr;
				f->newi = 2 * f->oldr * f->oldi + f->ci;
				if ((f->newr * f->newr + f->newi * f->newi) > 4)
					break ;
				i++;
			}
			f->color = colorpicker(i, f->maxiterations);
			if (i == f->maxiterations)
				f->color = 0;
			my_mlx_pixel_put(f, x, y, f->color);
			i = 0;
			x++;
		}
		x = 0;
		y++;
	}
}*/

static void	put_line_mandelbrot(t_frctl *f, t_draw d)
{
	f->pr = 1.5 * (d.x - d.w / 2) / (0.5 * f->zoom * d.w) + f->movex;
	f->pi = (d.y - d.h / 2) / (0.5 * f->zoom * d.h) + f->movey;
	f->newr = 0;
	f->newi = 0;
	f->oldr = 0;
	f->oldi = 0;
	while (d.i < f->maxiterations)
	{
		f->oldr = f->newr;
		f->oldi = f->newi;
		f->newr = f->oldr * f->oldr - f->oldi * f->oldi + f->pr;
		f->newi = 2 * f->oldr * f->oldi + f->pi;
		if ((f->newr * f->newr + f->newi * f->newi) > 4)
			break ;
		d.i++;
	}
	f->color = colorpicker(d.i, f->maxiterations);
	if (d.i == f->maxiterations)
		f->color = 0;
	my_mlx_pixel_put(f, d.x, d.y, f->color);
}

void		draw_fractal(t_frctl *f)
{
	t_draw	d;

	d.w = WIN_WIDHT - 1;
	d.h = WIN_HEIGHT - 1;
	d.x = 0;
	d.y = 0;
	d.i = 0;
	while (d.y < d.h)
	{
		while (d.x < d.w)
		{
			if (f->fractaltype == 2)
				put_line_mandelbrot(f, d);
			else
				put_line_julia(f, d);
			d.x++;
		}
		d.x = 0;
		d.y++;
	}
}
