/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:13 by vkeinane          #+#    #+#             */
/*   Updated: 2019/10/22 15:03:18 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
