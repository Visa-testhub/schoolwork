/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:26:24 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/02 18:20:28 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_substrlen(char const *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start] != c && s[start] != '\0')
	{
		start++;
		i++;
	}
	return (i);
}

static int	ft_substr(char const *s, char c)
{
	int	i;
	int	substr;

	i = 0;
	substr = 0;
	if (!(s))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			substr++;
		}
		i++;
	}
	return (substr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i[4];
	char	**str;

	if (!s)
		return (NULL);
	i[3] = ft_substr(s, c);
	if (!(str = (char**)malloc((i[3] + 1) * sizeof(char*))))
		return (NULL);
	i[2] = 0;
	i[0] = 0;
	while (s[i[0]] != '\0' && i[3] != 0)
	{
		if (s[i[0]] != c && (s[i[0] - 1] == c || i[0] == 0))
		{
			i[1] = ft_substrlen(s, i[0], c);
			str[i[2]] = ft_strsub(s, i[0], i[1]);
			i[2]++;
			i[3]--;
		}
		i[0]++;
	}
	str[i[2]] = NULL;
	return (str);
}
