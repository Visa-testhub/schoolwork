/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 10:39:20 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/06 21:38:35 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_mouse(int x, int y, t_frctl *f)
{
	if (f->fractaltype == 1)
	{
		f->cr = (((double)4 / (double)WIN_WIDHT) * (double)x) - (double)2;
		f->ci = (((double)4 / (double)WIN_HEIGHT) * (double)y) - (double)2;
		draw_image(f);
	}
	f->mousex = x;
	f->mousey = y;
	return (0);
}

int		deal_button(int button, int x, int y, t_frctl *f)
{
	if (button == 4)
		zoom_picture(43, f, 0);
	if (button == 5)
		zoom_picture(45, f, 0);
	f->mousex = x;
	f->mousey = y;
	f->movex += (f->mousex - WIN_WIDHT / 2) / (0.5 * f->zoom * WIN_WIDHT);
	f->movey += (f->mousey - WIN_HEIGHT / 2) / (0.5 * f->zoom * WIN_HEIGHT);
	draw_image(f);
	return (0);
}
