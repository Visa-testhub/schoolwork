/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:55:05 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/03 11:30:46 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	shutdown(int err)
{
	if (err == 1)
	{
		ft_putendl("Usage:");
		ft_putendl("./fractol Julia");
		ft_putendl("./fractol Mandelbrot");
		ft_putendl("./fractol Something");
	}
	exit (0);
}
