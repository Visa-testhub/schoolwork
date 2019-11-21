/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:16:00 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/21 12:21:50 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		usage_and_exit(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		usage_and_exit(2);
	validator(fd);/*HERE GOES THE TESTFILE FOR VALIDATION*/	
//	printf("%d\n",fd);
	return (0);
}
