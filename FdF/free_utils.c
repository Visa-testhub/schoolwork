/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:53:08 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/22 18:47:19 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_int_arrays(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->height)
		free(fdf->z[i++]);
	free(fdf->z);
}

void	free_arrays(char **arr1, char *arr2)
{
	int		i;

	i = -1;
	while (arr1[++i])
		free(arr1[i]);
	free(arr1);
	free(arr2);
	arr1 = NULL;
	arr2 = NULL;
}

void	free_linked_list(t_row *head)
{
	t_row	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->z);
		free(tmp);
	}
}
