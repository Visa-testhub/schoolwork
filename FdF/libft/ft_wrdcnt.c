/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:58:12 by vkeinane          #+#    #+#             */
/*   Updated: 2020/07/18 12:53:32 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function takes string and delimiter, and counts words divided by delimiter.
** If string doesnt contain any delimiters,
** the string is considered to be one word long.
*/

int	ft_wrdcnt(char *s, int delim)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!(s))
		return (0);
	while (s[i] == delim && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == delim && s[i + 1] != delim && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}
