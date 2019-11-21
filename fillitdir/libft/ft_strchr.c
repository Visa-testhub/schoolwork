/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:35:14 by vkeinane          #+#    #+#             */
/*   Updated: 2019/10/25 15:05:05 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ns;

	i = 0;
	ns = (char *)s;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (ns + i);
	return (0);
}