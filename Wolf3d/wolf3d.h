/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:13:26 by vkeinane          #+#    #+#             */
/*   Updated: 2020/09/24 10:52:13 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIN_WIDHT 1080
# define WIN_HEIGHT 720
# define MAP_OFFSET 32
# define MAX_INT 214748367
# define RAY_AMOUNT WIN_WIDHT
# define FOV 60
# define DEGREE 0.0174532925
# define SKYCOLOR 0x000022
# define FLOORCOLOR 0x111111
# define MINIMAP_COLOR 0x9900
# define RED 0x900000
# define BLUE 0x90
# define DARKRED 0x200000
# define DARKBLUE 0x20

# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_cord{
	int			x;
	int			y;
}				t_cord;

typedef struct	s_cord_d{
	double		x;
	double		y;
}				t_cord_d;

typedef struct	s_cord_f{
	float		x;
	float		y;
}				t_cord_f;

typedef struct	s_ray{
	int			mapx;
	int			mapy;
	int			mapoffx;
	int			mapoffy;
	int			dof;
	int			dir;
	float		stepx;
	float		stepy;
	float		tan;
	float		y;
	float		x;
	float		angle;
}				t_ray;

typedef struct	s_read{
	int			isplayer;
	int			lastline;
	int			firstline;
	int			ret;
	int			widht;
	int			w_max;
	int			w_min;
	int			height;
}				t_read;

typedef struct	s_line{
	int			len_x;
	int			len_y;
	int			dx1;
	int			dy1;
	int			dx2;
	int			dy2;
	int			longer;
	int			shorter;
	int			calc;
	int			count;
}				t_line;

typedef struct	s_minimap{
	t_cord		*curr;
	t_cord		*start;
	t_cord		*end;
	t_cord		*sq_s;
	t_cord		*sq_e;
	t_cord		*p;
}				t_minimap;

typedef struct	s_wolf{
	t_minimap	*mm;
	t_cord		*tex;
	t_cord_d	*delta;
	t_cord_d	*player;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			toggle_compass;
	int			toggle_minimap;
	int			toggle_sprint;
	int			toggle_help;
	int			bpp;
	int			line_lenght;
	int			endian;
	int			color;
	int			**map;
	int			***texture;
	int			height;
	int			widht;
	int			mapoff;
	int			walltype[3];
	double		raylen_h;
	double		raylen_v;
	double		dist;
	double		camera_dist;
	float		line_h;
	float		pangle;
}				t_wolf;

int				validate(int fd, t_read *r, t_wolf *s);
int				deal_key(int key, t_wolf *s);
int				exit_pressed(void);
int				***init_textures(void);
void			shutdown(int err);
void			file_read(char *filename, t_wolf *s);
void			draw_init(t_wolf *s);
void			draw_minimap(t_minimap *m, t_wolf *s);
void			draw(t_wolf *s);
void			draw_image(t_wolf *s);
void			cast_rays(t_wolf *s);
void			draw_slice(int raynb, t_wolf *s, float rayangle);
void			draw_line(t_cord s, t_cord e, t_wolf st);
void			draw_compass(t_wolf *s);
void			stepdist_horizontal(t_wolf *s, t_ray *ray);
void			stepdist_vertical(t_wolf *s, t_ray *ray);
void			ray_endpoint(t_wolf *s, t_ray *r, int type);
void			pixel_to_img(t_wolf *s, int x, int y, int color);
t_minimap		*init_minimap(void);

#endif
