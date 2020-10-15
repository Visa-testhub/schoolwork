/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:50:01 by vkeinane          #+#    #+#             */
/*   Updated: 2020/10/15 13:06:04 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDHT 800
# define WIN_HEIGHT 600
# define PRECISION_BORDER 0x800000000000000

# include "libft.h"
# include "mlx.h"
# include "keys.h"
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
	int			maxiterations;
	double		mousex;
	double		mousey;
	double		cr;
	double		ci;
	double		pr;
	double		pi;
	double		zoom;
	double		movex;
	double		movey;
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
int				exit_pressed(void);
void			get_thread(t_frctl *f, t_draw *d);
void			zoom_picture(int key, t_frctl *f, int type);
void			shutdown(int err);
void			draw_image(t_frctl *f);
void			draw_init(t_frctl *f);
void			draw_fractal(t_frctl *f);

#endif
