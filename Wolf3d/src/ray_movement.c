/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:17:38 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/24 10:52:43 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Stepdist functions to get step lenght for each ray direction,
** stepdist_horizontal sets stepdistance so that the ray searches for
** horizontal walls. Meaning that ray y position always goes forward one
** map offset, and x is found with tangent and one side and other way around,
** with vertical rays. Offset decides the lenght that ray gets added to it.
**
** Infinite stepdistance is for the situations that one step in that direction
** would go forward forever, example looking for vertical valls and the
** angle would be half of pi or 180 degrees.
**
** Ray endpoint searches for a wall. Ray goes one step forward set by the
** rules of stepdist. And in that place looks if that map place has wall in it
** if no walls are found within twenty steps, the search is stopped.
*/

static void	infinite_stepdist(t_wolf *s, t_ray *ray)
{
	ray->dir = 0;
	ray->x = s->player->x;
	ray->y = s->player->y;
	ray->dof = 25;
}

void		stepdist_horizontal(t_wolf *s, t_ray *ray)
{
	if (ray->angle > M_PI)
	{
		ray->dir = 1;
		ray->y = round(s->player->y);
		while (((int)ray->y % MAP_OFFSET) != 0)
			ray->y--;
		ray->y -= 0.1;
		ray->x = (s->player->y - ray->y) * ray->tan + s->player->x;
		ray->stepy = -MAP_OFFSET;
		ray->stepx = -ray->stepy * ray->tan;
	}
	if (ray->angle < M_PI)
	{
		ray->dir = 2;
		ray->y = round(s->player->y);
		while (((int)ray->y % MAP_OFFSET) != 0)
			ray->y++;
		ray->x = (s->player->y - ray->y) * ray->tan + s->player->x;
		ray->stepy = MAP_OFFSET;
		ray->stepx = -ray->stepy * ray->tan;
	}
	if (ray->angle == 0 || ray->angle == M_PI)
		infinite_stepdist(s, ray);
}

void		stepdist_vertical(t_wolf *s, t_ray *ray)
{
	if (ray->angle > M_PI / 2 && ray->angle < 3 * M_PI / 2)
	{
		ray->dir = 1;
		ray->x = round(s->player->x);
		while (((int)ray->x % MAP_OFFSET) != 0)
			ray->x--;
		ray->x -= 0.1;
		ray->y = (s->player->x - ray->x) * ray->tan + s->player->y;
		ray->stepx = -MAP_OFFSET;
		ray->stepy = -ray->stepx * ray->tan;
	}
	if (ray->angle < M_PI / 2 || ray->angle > 3 * M_PI / 2)
	{
		ray->dir = 2;
		ray->x = round(s->player->x);
		while (((int)ray->x % MAP_OFFSET) != 0)
			ray->x++;
		ray->y = (s->player->x - ray->x) * ray->tan + s->player->y;
		ray->stepx = MAP_OFFSET;
		ray->stepy = -ray->stepx * ray->tan;
	}
	if (ray->angle == M_PI / 2 || ray->angle == 3 * M_PI / 2)
		infinite_stepdist(s, ray);
}

void		ray_endpoint(t_wolf *s, t_ray *ray, int type)
{
	while (ray->dof < 25)
	{
		ray->mapx = (int)(ray->x) / MAP_OFFSET;
		ray->mapy = (int)(ray->y) / MAP_OFFSET;
		ray->mapoffx = (int)(ray->x) % MAP_OFFSET;
		ray->mapoffy = (int)(ray->y) % MAP_OFFSET;
		if (ray->mapx < 0 || ray->mapy < 0 || \
				ray->mapx >= s->widht || ray->mapy >= s->height)
			break ;
		if (s->map[ray->mapy][ray->mapx] == 1 || \
				s->map[ray->mapy][ray->mapx] == 3)
		{
			ray->dof = 25;
			if (s->map[ray->mapy][ray->mapx] == 1)
				s->walltype[type] = 0;
			if (s->map[ray->mapy][ray->mapx] == 3)
				s->walltype[type] = 1;
		}
		else
		{
			ray->x += ray->stepx;
			ray->y += ray->stepy;
			ray->dof++;
		}
	}
}
