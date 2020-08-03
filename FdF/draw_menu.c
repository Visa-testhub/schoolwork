/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:45:08 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/27 12:46:33 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_menu_top(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 20, 0xFFFFFF,
					"To move the projection,");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 40, 0xFFFFFF,
					"up, down, left or right");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 60, 0xFFFFFF,
					"use matching arrow keys.");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 120, 0xFFFFFF,
					"To zoom the picture,");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 140, 0xFFFFFF,
					"use keys i, o");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 200, 0xFFFFFF,
					"Increase and decrease");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 220, 0xFFFFFF,
					"altitude, with +, -");
}

void	put_menu_bottom(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 280, 0xFFFFFF,
					"change projections");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 300, 0xFFFFFF,
					"with key p");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 360, 0xFFFFFF,
					"First projection:");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 380, 0xFFFFFF,
					"   isometric");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 400, 0xFFFFFF,
					"Second projection:");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 420, 0xFFFFFF,
					"   cabinet");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 440, 0xFFFFFF,
					"Third projection:");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 460, 0xFFFFFF,
					"curved perspective");
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDHT + 5, 500, 0xFFFFFF,
					"Enable color wiht c");
}
