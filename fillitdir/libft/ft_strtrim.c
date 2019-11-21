/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 08:47:14 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/01 18:11:24 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	j = (ft_strlen(s) - 1);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == j + 1)
	{
		if (!(str = malloc(1 * sizeof(char))))
			return (NULL);
		str[k] = '\0';
		return (str);
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	str = ft_strsub(s, i, j - i + 1);
	return (str);
}
