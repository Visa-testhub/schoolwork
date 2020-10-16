/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:26:19 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/28 18:56:11 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = i;
		while (haystack[k] == needle[j] && k < len)
		{
			k++;
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
