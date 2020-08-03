/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:37:09 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/21 21:53:53 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Changes the size of block referenced by ptr to "newsize",
**	by mowing the block to a larger storage area.
**	crealloc requires the ptr array to end in '\0' to work properly.
**	if the required memory block is equal or smaller than previous memoryblock,
**	the old ptr is returned.
**	the return value is a pointer to the new area of memory.
**	the old block of memory is released.
*/

char	*ft_crealloc(char *ptr, size_t newsize)
{
	char	*ptr2;

	if (!(ptr))
		return (NULL);
	if (newsize <= ft_strlen(ptr))
		return (ptr);
	if (!(ptr2 = (char *)malloc((newsize + 1) * sizeof(char))))
		return (NULL);
	ptr2 = ft_strcpy(ptr2, ptr);
	free(ptr);
	return (ptr2);
}
