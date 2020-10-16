/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:53:23 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/23 20:48:47 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		exit_pressed(void)
{
	shutdown(0);
	return (0);
}

void	shutdown(int err)
{
	if (err == 1)
		ft_putendl("Usage: ./wolf3d mapfile");
	if (err == 2)
		ft_putendl("Mapfile must be a file.");
	if (err == 3)
		ft_putendl("Mapfile invalid.");
	if (err == 4)
		ft_putendl("Map assembly failed");
	if (err == 5)
		ft_putendl("Malloc Failed");
	if (err == 6)
		ft_putendl("Texture file corrupted");
	if (err == 7)
		ft_putendl("Read failed");
	if (err == 8)
		ft_putendl("Could not open texture file");
	if (err == 9)
		ft_putendl("Close failed");
	exit(0);
}
