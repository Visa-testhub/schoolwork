/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:28:11 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/21 16:22:20 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	tetr{
	char		**arr;
	int			row;
	int 		column;
	struct tetr	*point;
}				tblock;

int 	main(int argc, char **argv);
int		validator(int fd);
void	usage_and_exit(int a);

#endif
