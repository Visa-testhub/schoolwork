/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:16:00 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/27 14:42:34 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	tblock blocks[26];
	int i;

	i = 0;
	if (argc != 2)
		usage_and_exit(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		usage_and_exit(2);
	validate(blocks, fd);		/*HERE GOES THE TESTFILE FOR VALIDATION*/	
	close(fd);
	assemble(blocks);
/*	while (blocks[i].type >= 'A' && blocks[i].type <= 'Z')
	{	printf("%lu\n",blocks[i].block);
		i++;}
*/	
	return (0);
}
