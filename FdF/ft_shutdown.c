/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shutdown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:42:27 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/23 21:42:12 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shutdown(int e)
{
	if (e == 1)
		ft_putstr("Wrong number of arguments.\n");
	if (e == 2)
		ft_putstr("Invalid map file.\n");
	if (e == 3)
		ft_putstr("Memory allocation failure\n");
	if (e == 4)
	{
		ft_putendl("You know what would be great ?");
		ft_putendl("File with TWO points to connect");
	}
	if (e == 5)
		ft_putendl("Cannot read directories.");
	exit(0);
}

void	end_program(t_fdf *fdf)
{
	free_int_arrays(fdf);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	ft_putstr("bye\n");
	exit(0);
}
