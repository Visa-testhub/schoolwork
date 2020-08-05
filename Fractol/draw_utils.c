/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:01:13 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/05 13:54:35 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	get_thread(t_frctl *f, t_draw *d)
{
	if (f->thread1 == (int)pthread_self())
	{
		d->y = 0;
		d->h = 200;
	}
	if (f->thread2 == (int)pthread_self())
	{
		d->y = 200;
		d->h = 400;
	}
	if (f->thread3 == (int)pthread_self())
	{
		d->y = 400;
		d->h = WIN_HEIGHT - 1;
	}
}

int		colorpicker(int i, t_frctl *f)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (f->color == 2)
	{
		r = 0;
		g = 70 + (i % f->maxiterations) * 4;
		b = (i % f->maxiterations) * 4;
	}
	if (f->color == 1)
	{
		r = i * 20;
		g = i * 40;
		b = i * 30;
	}
	if (f->color == 0)
	{
		b = (i % f->maxiterations) * 4;
		g = (i % f->maxiterations) * 4;
		r = (i % f->maxiterations) * 4;
	}
	return (r << 16 | b << 8 | b);
}

void	draw_init(t_frctl *f)
{
	if (f->fractaltype == 1)
		f->movex = 0;
	else
		f->movex = -0.6;
	f->movey = 0;
	f->mousex = 0;
	f->mousey = 0;
	f->cr = -0.6;
	f->ci = 0.27015;
	f->zoom = 1;
	f->color = 0;
	f->maxiterations = 50;
}
