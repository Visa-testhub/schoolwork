/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:06:31 by vkeinane          #+#    #+#             */
/*   Updated: 2019/10/25 15:11:30 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ns;

	i = ft_strlen(s);
	ns = (char *)s;
	while (i >= 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return (ns + i);
	return (0);
}
