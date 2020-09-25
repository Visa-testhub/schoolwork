/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:21:17 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/25 10:47:30 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_pressed(void)
{
	ft_shutdown(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		ft_shutdown(1);
	if (open(argv[1], O_DIRECTORY) != -1)
		ft_shutdown(5);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_shutdown(2);
	if (reader(fd, &fdf))
		ft_shutdown(2);
	fdf.mlx = mlx_init();
	fdf.img = mlx_new_image(fdf.mlx, WIN_WIDHT, WIN_HEIGHT);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pix, &fdf.line_lenght,
			&fdf.endian);
	fdf.win = mlx_new_window(fdf.mlx, WIN_WIDHT + MENU_WIDHT,
								WIN_HEIGHT, "fdf");
	draw_init(&fdf);
	draw_isometric_map(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_hook(fdf.win, 17, 0L, exit_pressed, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, deal_key, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
