/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:59:45 by vkeinane          #+#    #+#             */
/*   Updated: 2019/11/01 19:59:40 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int i;
	int j;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
		i++;
	j = 0;
	while (j <= i)
	{
		s[j] = '\0';
		j++;
	}
}
