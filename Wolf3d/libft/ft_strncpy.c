/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:34:00 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/01 19:13:50 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (src[i] == '\0')
		{
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
		}
		if (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
