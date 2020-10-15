/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:46:55 by vkeinane          #+#    #+#             */
/*   Updated: 2020/10/15 13:08:05 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_pressed(void)
{
	shutdown(0);
	return (0);
}

static void	display_usage(void)
{
	ft_putendl("Change fractals      : f");
	ft_putendl("Change colorscheme   : c");
	ft_putendl("Reset to start values: r");
	ft_putendl("Zoom in and out      : + , -");
	ft_putendl("Change accuracy      : i, o\n");
	ft_putendl("Make Julia set vary by moving mouse over the image");
	ft_putendl("Zoom in mouse location by howering the mouse over image,");
	ft_putendl("and scrolling up or down.");
	ft_putendl("Move to mouse location by clicking,");
	ft_putendl("while cursor is over the image");
}

static int	read_input(char *str, t_frctl *f)
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
	if (!(ft_strcmp("Burningship", str)))
	{
		f->fractaltype = 3;
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_frctl	f;

	if ((argc != 2) || (read_input(argv[1], &f)))
		shutdown(1);
	display_usage();
	f.mlx = mlx_init();
	f.img = mlx_new_image(f.mlx, WIN_WIDHT, WIN_HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_lenght, &f.endian);
	f.win = mlx_new_window(f.mlx, WIN_WIDHT, WIN_HEIGHT, "Fract'ol");
	draw_init(&f);
	draw_image(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_hook(f.win, 6, 1L << 6, deal_mouse, &f);
	mlx_hook(f.win, 17, 0L, exit_pressed, &f);
	mlx_mouse_hook(f.win, deal_button, &f);
	mlx_hook(f.win, 2, 1L << 0, deal_key, &f);
	mlx_loop(f.mlx);
	return (0);
}
