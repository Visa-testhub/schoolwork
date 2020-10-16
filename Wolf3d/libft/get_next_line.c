/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:17:48 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/12 21:50:08 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lcheck(char *bufcpy, int rb)
{
	int		i;

	i = 0;
	if (bufcpy == NULL)
		return (-1);
	while (bufcpy[i] && bufcpy[i] != '\n')
		i++;
	if (bufcpy[i] == '\n' || rb == 0)
		return (i);
	else
		return (-1);
}

static int	ft_check(char *bufcpy, int rb)
{
	int		i;

	i = 0;
	if (bufcpy == NULL)
		return (-1);
	while (bufcpy[i] && bufcpy[i] != '\n')
		i++;
	if (bufcpy[i] == '\n')
		return (i + 1);
	else if (rb == 0)
		return (i);
	else
		return (-1);
}

static char	*ft_read_n_cpy(char *bufcpy, char *buffer, int rb)
{
	char	*temp1;
	char	*temp2;

	if (!(bufcpy))
	{
		if (!(bufcpy = ft_strsub((const char *)buffer, 0, rb)))
			return (NULL);
	}
	else
	{
		if (!(temp2 = ft_strsub((const char *)buffer, 0, rb)))
			return (NULL);
		temp1 = bufcpy;
		if (!(bufcpy = ft_strjoin(temp1, temp2)))
			return (NULL);
		ft_strdel(&temp1);
		ft_strdel(&temp2);
	}
	return (bufcpy);
}

static int	ft_checkout(int rb, char **bufcpy, char **line, int fd)
{
	if (rb == 0 && bufcpy[fd][0] == '\0' && *line[0] == '\0')
	{
		ft_strdel(&bufcpy[fd]);
		ft_strdel(line);
		return (0);
	}
	else if (rb < 0 || bufcpy[fd] == NULL)
		return (-1);
	else
		return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*bufcpy[MAX_FD];
	char			buffer[BUFF_SIZE];
	char			*temp1;
	int				rb;

	if (fd < 0 || fd > MAX_FD - 1 || line == NULL)
		return (-1);
	rb = 1;
	while (ft_check(bufcpy[fd], rb) == -1)
	{
		rb = read(fd, buffer, BUFF_SIZE);
		if (rb < 0)
			return (-1);
		bufcpy[fd] = ft_read_n_cpy(bufcpy[fd], buffer, rb);
		if (bufcpy[fd] == NULL)
			return (-1);
	}
	if (!(*line = ft_strsub(bufcpy[fd], 0, ft_lcheck(bufcpy[fd], rb))))
		return (-1);
	temp1 = bufcpy[fd];
	if (!(bufcpy[fd] = ft_strsub(bufcpy[fd], ft_check(bufcpy[fd], rb), BUFX2)))
		return (-1);
	ft_strdel(&temp1);
	return (ft_checkout(rb, bufcpy, line, fd));
}
