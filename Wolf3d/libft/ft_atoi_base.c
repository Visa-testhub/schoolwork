/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:21:24 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/17 15:02:51 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isbasenb(char c, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789ABCDEF";
	c = ft_toupper(c);
	while (i < base)
		if (str[i++] == c)
			return (1);
	return (0);
}

int			ft_atoi_base(const char *str, int base)
{
	int	i;
	int	nb;
	int	sign;

	if (base < 2 || base > 16 || !str)
		return (0);
	i = 0;
	nb = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && isbasenb(str[i], base))
	{
		if (ft_isdigit(str[i]))
			nb = (nb * base) + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			nb = (nb * base) + (str[i] - 'a' + 10);
		else
			nb = (nb * base) + (str[i] - 'A' + 10);
		i++;
	}
	return (nb * sign);
}
