/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:53:09 by cion              #+#    #+#             */
/*   Updated: 2018/01/23 16:53:48 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct	s_point
{
	float x;
	float y;
	float z;
}				t_point;

typedef struct	s_line
{
	int		error1;
	int		error2;
	int		sign_x;
	int		sign_y;
	int		dx;
	int		dy;
	int		color;
}				t_line;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*image;
	int			**matrix;
	int			row;
	int			col;
	int			scale;
	int			scale_z;
	int			x_offset;
	int			y_offset;
	int			projection;
	int			color;
	t_point		p1;
	t_point		p2;
	t_point		**init;
	t_point		**pts;
	t_point		**trans;
	t_line		line;
}				t_env;

void			ft_error(int argc, int fd);
void			set_basic(t_env *world);
void			event_1(int key_code, t_env *world);
void			event_2(int key_code, t_env *world);
void			draw_picture_1(t_env *world);
void			draw_picture_2(t_env *world);
void			create_window(t_env	*world);
void			draw_line(t_env	*world);
void			set_default(t_env *world);
void			set_color_1(t_env *world, int i, int j);
void			set_color_2(t_env *world, int i, int j);
void			put_pixel_img(t_env *world, int x, int y, int color);
void			img_clear(t_env *world);
void			translate(t_env *world);
void			choose_color_1(t_env *world, int i, int j);
void			choose_color_2(t_env *world, int i, int j);
void			x_rotation(t_env *world, float angle);
void			y_rotation(t_env *world, float angle);
void			z_rotation(t_env *world, float angle);
void			calc_x_rot(float *y, float *z, float angle);
void			calc_y_rot(float *x, float *z, float angle);
void			calc_z_rot(float *x, float *y, float angle);
void			make_points(t_env *world);
int				main_activity(t_env *world);
int				my_key_func(int key_code, t_env *world);
int				**make_matrix(char **map, t_env *world);
int				round_number(float number);
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
void			ft_draw_controls(t_env *world);
t_point			trans_point_iso(t_point p, t_env *world);
t_point			trans_point_cab(t_point p, t_env *world);
t_point			trans_point_plan(t_point p, t_env *world);

#endif
