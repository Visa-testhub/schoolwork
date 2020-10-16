/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:19:54 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/23 14:35:27 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_wolf	s;

	if (ac != 2)
		shutdown(1);
	if (open(av[1], O_DIRECTORY) != -1)
		shutdown(2);
	file_read(av[1], &s);
	s.texture = init_textures();
	s.mm = init_minimap();
	s.mlx = mlx_init();
	s.img = mlx_new_image(s.mlx, WIN_WIDHT, WIN_HEIGHT);
	s.addr = mlx_get_data_addr(s.img, &s.bpp, &s.line_lenght, &s.endian);
	s.win = mlx_new_window(s.mlx, WIN_WIDHT, WIN_HEIGHT, "Wolf3D");
	draw_init(&s);
	mlx_hook(s.win, 17, 0L, exit_pressed, &s);
	mlx_hook(s.win, 2, 1L << 0, deal_key, &s);
	mlx_loop(s.mlx);
	return (0);
}
