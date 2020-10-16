/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:33:26 by vkeinane          #+#    #+#             */
/*   Updated: 2019/10/24 15:50:44 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ndst;
	const unsigned char	*nsrc;

	i = 0;
	ndst = (unsigned char *)dst;
	nsrc = (const unsigned char *)src;
	if (nsrc < ndst)
	{
		i = len;
		while (i-- != 0)
			ndst[i] = nsrc[i];
	}
	else
		ft_memcpy(dst, src, len);
	return (ndst);
}
