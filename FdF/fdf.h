/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkeinane <vkeinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:41 by vkeinane          #+#    #+#             */
/*   Updated: 2020/10/14 10:02:27 by vkeinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_ROW 1000
# define WIN_WIDHT 960
# define WIN_HEIGHT 540
# define MENU_WIDHT 250
# define START_COLOR 44031

# include "mlx.h"
# include "keys.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_cord{
	int				x;
	int				y;
	int				z;
}					t_cord;

typedef struct		s_line{
	int				len_x;
	int				len_y;
	int				dx1;
	int				dy1;
	int				dx2;
	int				dy2;
	int				longer;
	int				shorter;
	int				calc;
	int				count;
}					t_line;

typedef struct		s_fdf{
	void			*img;
	void			*mlx;
	void			*win;
	char			*addr;
	int				bits_per_pix;
	int				line_lenght;
	int				endian;
	int				up_down;
	int				left_right;
	int				projection;
	int				w_max;
	int				w_min;
	int				widht;
	int				height;
	int				grid_w;
	int				grid_h;
	int				alt_mult;
	int				gap;
	int				color;
	int				color_on;
	int				**z;
}					t_fdf;

typedef struct		s_row{
	int				*z;
	struct s_row	*next;
}					t_row;

int					deal_key(int key, t_fdf *fdf);
int					reader(int fd, t_fdf *fdf);
int					exit_pressed(void);
int					get_color(t_cord start, t_cord end, int dist, int maxdist);
void				draw_line(t_cord s, t_cord e, t_fdf fdf);
void				draw_isometric_map(t_fdf *fdf);
void				draw_cabinet_map(t_fdf *fdf);
void				draw_perspective_map(t_fdf *fdf);
void				gap_init(t_fdf *fdf);
void				ft_swap(int *a, int *b);
void				ft_shutdown(int e);
void				my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void				free_linked_list(t_row *head);
void				free_arrays(char **arr1, char *arr2);
void				free_int_arrays(t_fdf *fdf);
void				gap_init(t_fdf *fdf);
void				draw_init(t_fdf *fdf);
void				put_menu_top(t_fdf *fdf);
void				put_menu_bottom(t_fdf *fdf);
void				next_point_isometric(t_fdf *fdf, t_cord *cur,
											t_cord *next, int y);
void				next_point_cabinet(t_fdf *fdf, t_cord *cur,
											t_cord *next, int y);
void				next_point_perspective(t_fdf *fdf, t_cord *cur,
											t_cord *next, int y);
void				end_program(t_fdf *fdf);
#endif
