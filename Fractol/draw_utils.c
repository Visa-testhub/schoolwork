/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:01:13 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/03 15:14:49 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int		colorpicker(int i, int maxi)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

//	b = (i % maxi) * 2;
//	g = (100 + (i % maxi)) * 2;
//	r = (50 + (i % maxi)) >> 1;
	b = (i % maxi) * 4;//black and white
	g = (i % maxi) * 4;
	r = (i % maxi) * 4;
	return (r << 16 | b << 8 | b);
}

void	draw_init(t_frctl *f)
{
	if (f->fractaltype == 1)
		f->movex = 0;
	else
		f->movex = -0.6;
	f->mousex = 0;
	f->mousey = 0;
	f->cr = -0.6;
	f->ci = 0.27015;
	f->zoom = 1;
	f->movey = 0;
	f->maxiterations = 50;
}
