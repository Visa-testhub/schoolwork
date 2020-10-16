/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:21:40 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/23 20:54:02 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_colors(int **tex, char *l, t_cord *c)
{
	int		i;
	int		j;
	char	buff[10];

	j = 0;
	i = -1;
	while (l[++i])
		if (!((l[i] >= '0' && l[i] <= '9') || (l[i] >= 'a' && l[i] <= 'f') || \
			(l[i] >= 'A' && l[i] <= 'F') || l[i] == ' ' || l[i] == 'x'))
			shutdown(6);
	i = -1;
	while (l[++i] && c->x < 128)
	{
		if (l[i] == '0' && l[i + 1] == 'x')
		{
			i += 2;
			while (l[i] && !(ft_iswhitespace(l[i])))
				buff[j++] = l[i++];
			buff[j] = '\0';
			tex[c->y][c->x] = ft_atoi_base(buff, 16);
			j = 0;
			c->x++;
			i--;
		}
	}
}

static void	open_texturefile(int *fd, int *tex_nb)
{
	if (*tex_nb == 0)
		*fd = open("textures/mossy_stone.w", O_RDONLY);
	else
		*fd = open("textures/stone.w", O_RDONLY);
	if (*fd < 0)
		shutdown(8);
}

static void	read_textures(int ***texture, int tex_nb)
{
	char	*line;
	int		fd;
	int		ret;
	t_cord	c;

	ret = 0;
	c.x = 0;
	c.y = 0;
	line = NULL;
	open_texturefile(&fd, &tex_nb);
	while ((ret = get_next_line(fd, &line)) && c.y < 32)
	{
		if (ret < 0 || !(line))
			shutdown(7);
		get_colors(*texture, line, &c);
		c.x = 0;
		c.y++;
		free(line);
	}
	if (close(fd))
		shutdown(9);
}

static int	***texture_space(void)
{
	int		***tex;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(tex = (int ***)malloc(2 * sizeof(int *))))
		shutdown(5);
	while (j < 2)
	{
		if (!(tex[j] = (int **)malloc(32 * sizeof(int *))))
			shutdown(5);
		while (i < 32)
		{
			if (!(tex[j][i] = (int *)malloc(128 * sizeof(int))))
				shutdown(5);
			i++;
		}
		i = 0;
		j++;
	}
	return (tex);
}

int			***init_textures(void)
{
	int		***texture;

	texture = texture_space();
	read_textures(texture, 0);
	read_textures(texture + 1, 1);
	return (texture);
}
