/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:19:38 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/01 16:09:07 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ns;
	unsigned char	nc;

	i = 0;
	ns = (unsigned char *)s;
	nc = (unsigned char)c;
	while (i < n)
	{
		if (ns[i] == nc)
			return (ns + i);
		i++;
	}
	return (NULL);
}
