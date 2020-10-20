/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:03:15 by vkeinane          #+#    #+#             */
/*   Updated: 2020/10/20 15:09:09 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		i,j;
	char	*line;

	i = 1;
	j = 1;
	line = NULL;
	if (argc > 3)
	{
		printf("No more than 2 arguments for this program :\)");
		return (0);
	}
	if (argc == 2)
		fd1 = open(argv[1], O_RDONLY);
	if (argc == 3)
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
	if (argc == 3){
		while (get_next_line(fd1, &line) || get_next_line(fd2, &line))
		{
			printf("%s\n", line);
			ft_strdel(&line);
			printf("%s\n", line);
			ft_strdel(&line);
		}
	}
	else if (argc == 2)
	{
		while (get_next_line(fd1, &line))
		{
			printf("%s\n", line);
			ft_strdel(&line);
		}
	}
	else
	{while (i != 0 && i != -1)
		{
			i = get_next_line(fd1, &line);
			printf("%d\n", i);
			printf("%s\n", line);
			ft_strdel(&line);
		}
	}
	return (0);
}
//previous working allocator for right size.
/*rb = read(fd, buffer, BUFF_SIZE);
  if (!(bufcpy[fd]))
  {
  if (!(bufcpy[fd] = ft_strsub((const char *)buffer, 0, rb)))
  return (-1);
  }
  else
  {
  temp2 = ft_strsub((const char *)buffer, 0, rb);
  temp1 = bufcpy[fd];
  bufcpy[fd] = ft_strjoin(temp1, temp2);
  ft_strdel(&temp1);
  ft_strdel(&temp2);
  }
*/
