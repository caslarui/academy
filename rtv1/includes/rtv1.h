/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:53:41 by user00            #+#    #+#             */
/*   Updated: 2018/05/20 12:51:52 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "img.h"
# include <mlx.h>
# include "../libft/includes/libft.h"
# define abs(x) ((x) < 0 ? (-x) : (x))
# define sqr(x) (abs(x)* abs(x))
# define TRUE 1
# define FALSE 0
# define KEY_ESC 53

typedef enum s_section
{
    SPHERE, CAMERA, CONE, CYLINDER, PLANE, LIGHT, NONE
    
}              t_section;

typedef struct s_ray
{
    t_vector o;
    t_vector dir;
    double t;

}              t_ray;

typedef struct	s_light
{
	t_vector		pos;
	t_vector		dir;
	t_ray		ray;
	double		to_obj_dist;
	double		to_intersect_dist;
}				t_light;

typedef struct s_op
{
	double		a;
	double		b;
	double		c;
	double		t1;
	double		t2;
	t_vector   	x;
	t_vector   	v;
	t_vector   	d;
	double		dv;
	double		xv;
	double		t;
	double		delta;
	double		m;

}              t_op;

typedef struct  s_point_i
{
    int x;
    int y;
}               t_point_i;

typedef struct  s_point_f
{
    double x;
    double y;
}               t_point_f;

typedef	struct		s_object
{
	int				id;
	t_section	    type;
	t_vector   		pos;
	t_vector   		rot;
	double			radius;
	double			length;
	t_color			color;
	t_vector   		intersection;
	t_vector   		normal;
}					t_object;

void			ft_get_distance(t_op *op);
int             ft_intersect_sphere(t_ray ray, t_object *obj);
void            ft_cam_new(t_cam *cam);
t_vector	        ft_cam_get_dir(t_cam *cam, t_point_i p, int width, int height);
t_object	    *ft_get_closest_object(t_ray ray, t_list *objects);
int             ft_intersect(t_ray ray, t_object *object);
t_color		    ft_ray_trace_light(t_list *lights, t_list *objects, 
                                                t_object *closest_obj);
void		    ft_intersect_light(t_light *light, t_list *objects,
                                    t_object *closest_obj, int *light_blocked);
int				ft_intersect_cone(t_ray ray, t_object *obj);
int				ft_intersect_cylinder(t_ray ray, t_object *obj);
int			    ft_intersect_object(t_ray ray, t_object *obj);
int 			ft_intersect_plane(t_ray, t_object *obj);
t_color		    ft_add_light(t_light *light, t_object *obj);
t_color         ft_rt(t_scene *sc, t_ray ray);
void			ft_draw_window(t_scene *sc);
int				ft_parse_light(t_list **lights, char *line);
int             ft_parse_camera(t_scene *scene, char *line);
int				ft_parse_object(t_list **objects, char *line);
int             ft_parse_scene(t_scene *sc, int fd);
int             ft_key_hook(int keycode, t_scene *sc);
int             ft_expose_hook(t_scene *sc);
void			ft_destroy_scene(t_scene *sc);
t_scene         *ft_new_scene(int fd);


#endif