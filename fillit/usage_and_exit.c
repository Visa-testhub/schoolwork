/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:20:47 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/27 11:26:36 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage_and_exit(int errortype)
{
	if (errortype == 1)
	{
		write(1, "usage: fillit target_file\n", 26);
		exit(0);
	}
	if (errortype == 2)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}
