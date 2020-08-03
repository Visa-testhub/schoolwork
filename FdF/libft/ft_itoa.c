/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:22:38 by vkeinane          #+#    #+#             */
/*   Updated: 2019/10/31 19:10:35 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mallocsize(int n)
{
	long	i;
	int		j;

	j = 0;
	if (n < 0)
	{
		j++;
		i = -1;
		while (i >= n)
		{
			i = i * 10;
			j++;
		}
	}
	if (n > 0)
	{
		i = 1;
		while (i <= n)
		{
			i = i * 10;
			j++;
		}
	}
	return (j);
}

static char	*ft_cstrcomp(char *str, int n, int j)
{
	if (n > 0)
	{
		while (j >= 0)
		{
			str[j] = '0' + (n % 10);
			n = (n - n % 10) / 10;
			j--;
		}
	}
	if (n < 0)
	{
		n = n * (-1);
		while (j > 0)
		{
			str[j] = '0' + (n % 10);
			n = (n - n % 10) / 10;
			j--;
		}
		str[j] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	i = ft_mallocsize(n);
	if (!(str = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	j = i - 1;
	str = ft_cstrcomp(str, n, j);
	str[i] = '\0';
	return (str);
}
