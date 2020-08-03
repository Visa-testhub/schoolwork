/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:56:01 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/01 16:02:10 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ndst;
	unsigned char		nc;
	const unsigned char	*nsrc;

	i = 0;
	nc = (unsigned char)c;
	ndst = (unsigned char *)dst;
	nsrc = (const unsigned char *)src;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		if (nsrc[i] == nc)
		{
			return (ndst + i + 1);
		}
		i++;
	}
	return (NULL);
}
