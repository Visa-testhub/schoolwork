/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:05:39 by vkeinane          #+#    #+#             */
/*   Updated: 2020/10/15 12:43:28 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_picture(int key, t_frctl *f, int type)
{
	if (key == PLUS_KEY)
	{
		if (type == 0)
		{
			f->movex += (f->mousex - WIN_WIDHT / 2) \
						/ (0.5 * f->zoom * WIN_WIDHT);
			f->movey += (f->mousey - WIN_HEIGHT / 2) \
						/ (0.5 * f->zoom * WIN_HEIGHT);
		}
		if (f->zoom > PRECISION_BORDER)
			f->zoom = PRECISION_BORDER;
		f->zoom = (f->zoom) * 1.5;
	}
	if (key == MINUS_KEY)
	{
		if (f->zoom < 0.01)
			f->zoom = 0.01;
		else
			f->zoom = f->zoom / 1.5;
	}
}

static void	move_picture(int key, t_frctl *f)
{
	if (key == LEFT_KEY)
		f->movex -= 0.05 / f->zoom;
	if (key == UP_KEY)
		f->movey -= 0.05 / f->zoom;
	if (key == RIGHT_KEY)
		f->movex += 0.05 / f->zoom;
	if (key == DOWN_KEY)
		f->movey += 0.05 / f->zoom;
}

static void	change_maxiteration(int key, t_frctl *f)
{
	if (key == I_KEY)
	{
		if (f->maxiterations < 10)
			f->maxiterations += 1;
		else if (f->maxiterations >= 10 && f->maxiterations < 0xF000000)
			f->maxiterations += 10;
		else if (f->maxiterations >= 0xF000000)
			f->maxiterations = 0xF000000;
		else
			f->maxiterations = 1;
	}
	if (key == O_KEY)
	{
		if (f->maxiterations <= 10 && f->maxiterations > 1)
			f->maxiterations -= 1;
		else if (f->maxiterations > 10)
			f->maxiterations -= 10;
		else
			f->maxiterations = 1;
	}
	ft_putnbr(f->maxiterations);
	ft_putendl(" Iterations");
}

static void	change_fractaltype(t_frctl *f)
{
	if (f->fractaltype == 1)
	{
		f->movey = 0;
		f->movex = -0.6;
		f->fractaltype = 2;
		ft_putendl("Fractaltype = Mandelbrot");
	}
	else if (f->fractaltype == 2)
	{
		f->movey = -0.5;
		f->movex = -0.5;
		f->fractaltype = 3;
		ft_putendl("Fractaltype = Burning ship");
	}
	else
	{
		f->movex = 0;
		f->movey = 0;
		f->fractaltype = 1;
		ft_putendl("Fractaltype = Julia");
	}
}

int			deal_key(int key, t_frctl *f)
{
	if (key == ESCAPE_KEY)
		shutdown(0);
	if (key == MINUS_KEY || key == PLUS_KEY)
		zoom_picture(key, f, 1);
	if (key == R_KEY)
		draw_init(f);
	if (key == RIGHT_KEY || key == LEFT_KEY || key == UP_KEY || key == DOWN_KEY)
		move_picture(key, f);
	if (key == I_KEY || key == O_KEY)
		change_maxiteration(key, f);
	if (key == F_KEY)
		change_fractaltype(f);
	if (key == C_KEY)
	{
		if (f->color == 0)
			f->color = 1;
		else if (f->color == 1)
			f->color = 2;
		else
			f->color = 0;
	}
	draw_image(f);
	return (0);
}
