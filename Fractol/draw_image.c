/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:03:27 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/03 15:09:10 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_image(t_frctl *f)
{
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIN_WIDHT, WIN_HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_lenght, &f->endian);
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
