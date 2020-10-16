/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:35:24 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/08 18:46:07 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function to push new node to the back of the linked list.
*/

void	ft_lstpb(t_list **begin_list, void const *content, size_t content_size)
{
	t_list	*list;

	list = *begin_list;
	if (!(list))
		list = ft_lstnew(content, content_size);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(content, content_size);
	}
}
