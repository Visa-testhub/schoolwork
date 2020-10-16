/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:24:01 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/02 17:59:48 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ns;
	unsigned int	i;
	unsigned int	k;

	i = start;
	k = 0;
	if (!s)
		return (NULL);
	if (!(ns = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < (start + len) && s[i] != '\0')
	{
		ns[k] = s[i];
		i++;
		k++;
	}
	ns[k] = '\0';
	return (ns);
}
