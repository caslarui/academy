/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:08:56 by user00            #+#    #+#             */
/*   Updated: 2018/05/20 12:45:08 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "../libft/includes/libft.h"


typedef struct  s_img
{
    void    *img_ptr;
    int     bpp;
    int     endian;
    int     size_line;
    char    *data;
}               t_img;

typedef struct	s_cam
{
	t_vector		pos;
	t_vector		rot;
	t_vector		up;
	t_vector		right;
	t_vector		vp_up_left;
	double		vp_dist;
	double		vp_height;
	double		vp_width;
}				t_cam;

typedef struct		s_scene
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				width;
	int				height;
	t_cam			*cam;
	t_list			*objects;
	t_list			*lights;
}					t_scene;

typedef struct  s_color
{
    double r;
    double g;
    double b;
}               t_color;

t_color		ft_unit_color(t_color c);
t_color		ft_add_color(t_color a, t_color b);
t_color		ft_cross_color(t_color a, t_color b);
t_color		ft_mult_color(t_color c, double r);


#endif