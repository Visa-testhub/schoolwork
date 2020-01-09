/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:16:00 by vkeinane          #+#    #+#             */
/*   Updated: 2020/01/09 11:18:22 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**PUT SOME KIND OF TEST TO TEST IF THERE ARE MORE THAN 26 BLOCKSSSSSSSSSSSSS
*/

int	main(int argc, char **argv)
{
	int		fd;
	t_block	blocks[27];
	int		i;

	i = 0;
	if (argc != 2)
		usage_and_exit(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		usage_and_exit(2);
	validate(blocks, fd);
	close(fd);
	assemble(blocks);
	return (0);
}
