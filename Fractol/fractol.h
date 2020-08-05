/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:50:01 by vkeinane          #+#    #+#             */
/*   Updated: 2020/08/05 13:55:36 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDHT 800
# define WIN_HEIGHT 600
# define WIN_W WIN_WIDHT - 1
# define WIN_H WIN_HEIGHT - 1

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <pthread.h>
# include <math.h>

typedef struct	s_frctl{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_lenght;
	int			endian;
	int			fractaltype;
	int			color;
	int			thread1;
	int			thread2;
	int			thread3;
	double		mousex;
	double		mousey;
	double		cr;
	double		ci;
	double		pr;
	double		pi;
	double		zoom;
	double		movex;
	double		movey;
	int			maxiterations;
}				t_frctl;

typedef struct	s_draw{
	int			x;
	int			y;
	int			w;
	int			h;
	int			hmax;
	int			i;
	int			color;
	double		newr;
	double		newi;
	double		oldr;
	double		oldi;
	double		pr;
	double		pi;
}				t_draw;

int				deal_key(int key, t_frctl *f);
int				deal_button(int button, int x, int y, t_frctl *f);
int				deal_mouse(int x, int y, t_frctl *f);
int				colorpicker(int i, t_frctl *f);
void			get_thread(t_frctl *f, t_draw *d);
void			zoom_picture(int key, t_frctl *f);
void			shutdown(int err);
void			my_mlx_pixel_put(t_frctl *f, int x, int y, int color);
void			draw_image(t_frctl *f);
void			draw_init(t_frctl *f);
void			draw_fractal(t_frctl *f);

#endif
