/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:44:45 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/24 12:05:32 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_image(int key, t_fdf *fdf)
{
	if (key == UP_ARROW)
		fdf->up_down = fdf->up_down - 10;
	if (key == DOWN_ARROW)
		fdf->up_down = fdf->up_down + 10;
	if (key == RIGHT_ARROW)
		fdf->left_right = fdf->left_right + 10;
	if (key == LEFT_ARROW)
		fdf->left_right = fdf->left_right - 10;
	if (key == 105)
		fdf->gap++;
	if (key == 111)
		fdf->gap--;
	if (key == 43)
		fdf->alt_mult++;
	if (key == 45)
		fdf->alt_mult--;
}

/*
** Deal key is the function to rewrite the image evrytime key is pressed.
*/

int		deal_key(int key, t_fdf *fdf)
{
	if (key == ESCAPE_KEY)
		end_program(fdf);
	if (key == LEFT_ARROW || key == RIGHT_ARROW || key == UP_ARROW || \
		key == DOWN_ARROW || key == 43 || key == 45 ||key == 105 || key == 111)
		move_image(key, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDHT, WIN_HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pix,
				&fdf->line_lenght, &fdf->endian);
	if (key == C_KEY)
		fdf->color_on = fdf->color_on == 1 ? 0 : 1;
	if (key == 112)
		if (++fdf->projection == 3)
			fdf->projection = 0;
	if (fdf->projection == 0)
		draw_isometric_map(fdf);
	else if (fdf->projection == 1)
		draw_cabinet_map(fdf);
	else
		draw_perspective_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}
