/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:46:55 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/03 14:01:28 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	read_input(char *str, t_frctl *f)
{
	if (!(ft_strcmp("Julia", str)))
	{
		f->fractaltype = 1;
		return (0);
	}
	if (!(ft_strcmp("Mandelbrot", str)))
	{
		f->fractaltype = 2;
		return (0);
	}
	if (!(ft_strcmp("Something", str)))
	{
		f->fractaltype = 3;
		return (0);
	}
	return(1);
}


int	main(int argc, char **argv)
{
	t_frctl	f;

	if ((argc != 2) || (read_input(argv[1], &f)))
		shutdown(1);
	f.mlx = mlx_init();
	f.img = mlx_new_image(f.mlx, WIN_WIDHT, WIN_HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_lenght, &f.endian);
	f.win = mlx_new_window(f.mlx, WIN_WIDHT, WIN_HEIGHT, "Fract'ol");
	draw_init(&f);
	ft_putendl("init done, drawing image");
	ft_putnbr(f.fractaltype);
	draw_image(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_hook(f.win, 6, 1L << 6, deal_mouse, &f);
	mlx_mouse_hook(f.win, deal_button, &f);
	mlx_hook(f.win, 2, 1L << 0, deal_key, &f);
	mlx_loop(f.mlx);
	return (0);

}
