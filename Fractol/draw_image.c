/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:03:27 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/04 15:12:47 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	third_thread_init(t_frctl *f)
{
	f->thread3 = (int)pthread_self();
	draw_fractal(f);
}

void	second_thread_init(t_frctl *f)
{
	f->thread2 = (int)pthread_self();
	draw_fractal(f);
}

void	first_thread_init(t_frctl *f)
{
	f->thread1 = (int)pthread_self();
	draw_fractal(f);
}

void	draw_image(t_frctl *f)
{
	pthread_t	threads[3];

	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIN_WIDHT, WIN_HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_lenght, &f->endian);
	if (pthread_create(&threads[0], NULL, (void *)first_thread_init, f))
		shutdown(2);
	if (pthread_create(&threads[1], NULL, (void *)second_thread_init, f))
		shutdown(2);
	if (pthread_create(&threads[2], NULL, (void *)third_thread_init, f))
		shutdown(2);
	if (pthread_join(threads[0], NULL))
		shutdown(3);
	if (pthread_join(threads[1], NULL))
		shutdown(3);
	if (pthread_join(threads[2], NULL))
		shutdown(3);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
