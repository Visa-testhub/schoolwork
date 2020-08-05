/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:05:39 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/05 20:58:43 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"
# include <stdio.h>

void	zoom_picture(int key, t_frctl *f)
{
	if (key == 43)
	{
		if (f->zoom >= 1073741824)
			f->zoom = f->zoom;
		f->zoom = (f->zoom) * 2;
/*		if (f->zoom < 20)
			f->zoom++;
		else if (f->zoom >= 20 && f->zoom < 100)
			f->zoom += 2;
		else if (f->zoom >= 100 && f->zoom < 200)
			f->zoom += 5;
		else if (f->zoom >= 200 && f->zoom < 800)
			f->zoom += 10;
		else
			f->zoom += 50;*/
	}
	if (key == 45)
	{
		f->zoom = f->zoom / 2;
/*		if (f->zoom <= 20 && f->zoom > 1)
			f->zoom--;
		else if (f->zoom > 20 && f->zoom <= 100)
			f->zoom -= 2;
		else if (f->zoom > 100 && f->zoom <= 200)
			f->zoom -= 5;
		else if (f->zoom > 200)
			f->zoom -= 10;*/
	}
	printf("%f\n", f->zoom);
}

void	move_picture(int key, t_frctl *f)
{
	if (key == 65361)
		f->movex -= 0.05 / f->zoom;
	if (key == 65362)
		f->movey -= 0.05 / f->zoom;	
	if (key == 65363)
		f->movex += 0.05 / f->zoom;
	if (key == 65364)
		f->movey += 0.05 / f->zoom;
}

void	change_maxiteration(int key, t_frctl *f)
{
	if (key == 105)
	{
		if (f->maxiterations < 10)
			f->maxiterations += 1;
		else if (f->maxiterations >= 10)
			f->maxiterations += 10;
		else
			f->maxiterations = 1;
	}
	if (key == 111)
	{
		if (f->maxiterations <= 10 && f->maxiterations > 1)
			f->maxiterations -= 1;
		else if (f->maxiterations > 10)
			f->maxiterations -= 10;
		else
			f->maxiterations = 1;
	}

}

void	change_fractaltype(t_frctl *f)
{
	if (f->fractaltype == 1)
	{
		f->movex = -0.6;
		f->fractaltype = 2;
	}
	else if (f->fractaltype == 2)
	{
		f->movex = 0;
		f->fractaltype = 3;
	}
	else
	{
		f->movex = 0;
		f->fractaltype = 1;
	}
}

int		deal_key(int key, t_frctl *f)
{
	if (key == 65307)
		shutdown(0);
	if (key == 43 || key == 45)
		zoom_picture(key, f);
	if (key == 114)
		draw_init(f);
	if (key >= 65361 && key <= 65364)
		move_picture(key, f);;
	if (key == 105 || key == 111)
		change_maxiteration(key, f);
	if (key == 102)
		change_fractaltype(f);
	if (key == 99)
	{
		if (f->color == 0)
			f->color = 1;
		else if (f->color == 1)
			f->color = 2;
		else
			f->color = 0;
	}
	draw_image(f);
	ft_putstr("key pressed is \n");
	ft_putnbr(key);
	ft_putstr("\n zoom amount is \n");
	ft_putnbr(f->zoom);
	ft_putstr("\n");
	ft_putstr("Max iterations is \n");
	ft_putnbr(f->maxiterations);
	ft_putstr("\n");
	return (0);
}
