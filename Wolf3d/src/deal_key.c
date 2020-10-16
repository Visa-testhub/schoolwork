/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:36:43 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/23 14:48:56 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	wall_collision(t_wolf *s, int direction)
{
	int		x;
	int		y;

	if (direction == 1)
	{
		x = (s->player->x + s->delta->x) / MAP_OFFSET;
		y = (s->player->y + s->delta->y) / MAP_OFFSET;
	}
	else
	{
		x = (s->player->x - s->delta->x) / MAP_OFFSET;
		y = (s->player->y - s->delta->y) / MAP_OFFSET;
	}
	if (x > s->widht || y > s->height || x < 0 || y < 0)
		return (1);
	if (s->map[y][x] == 1)
		return (1);
	return (0);
}

static void	move_player(int key, t_wolf *s)
{
	if (key == W_KEY || key == UP_ARROW)
	{
		if (!(wall_collision(s, 1)))
		{
			s->player->x += s->delta->x;
			s->player->y += s->delta->y;
		}
	}
	if (key == S_KEY || key == DOWN_ARROW)
	{
		if (!(wall_collision(s, 0)))
		{
			s->player->x -= s->delta->x;
			s->player->y -= s->delta->y;
		}
	}
}

static void	rotate_player(int key, t_wolf *s)
{
	if (key == A_KEY || key == LEFT_ARROW)
	{
		s->pangle -= 0.15;
		if (s->pangle < 0)
			s->pangle = ((2 * M_PI) - 0.15);
		s->delta->x = cos(s->pangle) * s->toggle_sprint;
		s->delta->y = sin(s->pangle) * s->toggle_sprint;
	}
	if (key == D_KEY || key == RIGHT_ARROW)
	{
		s->pangle += 0.15;
		if (s->pangle > (2 * M_PI))
			s->pangle = 0;
		s->delta->x = cos(s->pangle) * s->toggle_sprint;
		s->delta->y = sin(s->pangle) * s->toggle_sprint;
	}
}

int			deal_key(int key, t_wolf *s)
{
	if (key == ESCAPE_KEY)
		shutdown(0);
	if (key == A_KEY || key == D_KEY || key == LEFT_ARROW || key == RIGHT_ARROW)
		rotate_player(key, s);
	if (key == W_KEY || key == S_KEY || key == UP_ARROW || key == DOWN_ARROW)
		move_player(key, s);
	if (key == C_KEY)
		s->toggle_compass = s->toggle_compass == 1 ? 0 : 1;
	if (key == M_KEY)
		s->toggle_minimap = s->toggle_minimap == 1 ? 0 : 1;
	if (key == SHIFT)
	{
		s->toggle_sprint = s->toggle_sprint == 3 ? 6 : 3;
		rotate_player(A_KEY, s);
		rotate_player(D_KEY, s);
	}
	if (key == H_KEY)
		s->toggle_help = s->toggle_help == 1 ? 0 : 1;
	draw_image(s);
	return (0);
}
