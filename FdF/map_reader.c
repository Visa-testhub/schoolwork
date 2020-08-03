/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:11:42 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/27 11:02:19 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Make linked list nodes out of the information taken in getnextline
*/

void	newnode(char **alt, int widht, t_row **head)
{
	t_row	*node;
	t_row	*tmp;
	int		i;

	i = -1;
	if (!(node = (t_row *)malloc(sizeof(t_row))))
		ft_shutdown(3);
	if (!(node->z = (int *)malloc(sizeof(int) * widht)))
		ft_shutdown(3);
	while (alt[++i] != NULL)
		node->z[i] = ft_atoi(alt[i]);
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}

/*
** Make grid z from linked list. The z is altitude.
** [x] and [y] refers to the place of the altitude value.
*/

int		**init_altlist(t_row *head, t_fdf *fdf)
{
	t_row	*tmp;
	int		**z;
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (!(z = (int **)malloc(fdf->height * sizeof(int *))))
		ft_shutdown(3);
	tmp = head;
	while (y < fdf->height)
	{
		if (!(z[y] = (int *)malloc(fdf->widht * sizeof(int))))
			ft_shutdown(3);
		while (x < fdf->widht)
		{
			z[y][x] = tmp->z[x];
			x++;
		}
		x = 0;
		y++;
		tmp = tmp->next;
	}
	return (z);
}

/*
** Check map file for invalid lines or characters.
** lines must all be same lenght and only 0 to 9 and
** - and ' ' characters allowed
*/

void	check_lines(char *l, t_fdf *fdf)
{
	int		i;
	int		decider;

	decider = 0;
	i = 0;
	while (l[i])
	{
		if (l[i] == ' ' || l[i] == '-' || l[i] == ',')
			decider = 1;
		if (l[i] >= '0' && l[i] <= '9')
			decider = 1;
		if (l[i] == ',')
			while (l[i + 1] != ' ' && l[i + 1])
				i++;
		if (decider == 0)
			ft_shutdown(2);
		decider = 0;
		i++;
	}
	if (fdf->w_min != fdf->w_max)
	{
		ft_putendl("All rows must be same lenght");
		ft_shutdown(2);
	}
}

/*
** reader is a function to read the input file and put it in a useful formation
*/

int		reader(int fd, t_fdf *fdf)
{
	char	*line;
	char	**alt;
	t_row	*head;

	head = NULL;
	fdf->w_max = 0;
	fdf->w_min = 2147483647;
	fdf->height = 0;
	while (get_next_line(fd, &line))
	{
		alt = ft_strsplit(line, ' ');
		fdf->widht = ft_wrdcnt(line, ' ');
		newnode(alt, fdf->widht, &head);
		fdf->w_max = fdf->widht > fdf->w_max ? fdf->widht : fdf->w_max;
		fdf->w_min = fdf->widht < fdf->w_min ? fdf->widht : fdf->w_min;
		check_lines(line, fdf);
		free_arrays(alt, line);
		fdf->height++;
	}
	close(fd);
	if (fdf->height == 0 || fdf->widht == 1)
		ft_shutdown(4);
	fdf->z = init_altlist(head, fdf);
	free_linked_list(head);
	return (0);
}
