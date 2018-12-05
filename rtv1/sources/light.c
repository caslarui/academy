/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:12:04 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:25 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color		ft_add_light(t_light *light, t_object *obj)
{
	t_vector	vec;
	t_color		c;
	double		angle;

	vec = ft_sub(obj->intersection, light->pos);
	angle = ft_dot(obj->normal, ft_neg(ft_unit_vector(vec)));
	if (angle <= 0)
		return ((t_color){0.0, 0.0, 0.0});
	c = ft_mult_color(ft_mult_color(obj->color, 1.0), angle);
	return (c);
}

void		ft_intersect_light(t_light *light, t_list *objects,
					t_object *closest_obj, int *light_blocked)
{
	t_object	*obj;

	while (objects)
	{
		obj = (t_object *)objects->content;
		if (obj->id != closest_obj->id)
		{
			if (ft_intersect_object(light->ray, obj))
			{
				light->to_intersect_dist = ft_length(ft_sub(obj->intersection,
					light->pos));
				if (light->to_intersect_dist < light->to_obj_dist)
					*light_blocked = TRUE;
			}
		}
		objects = objects->next;
	}
}

t_color		ft_ray_trace_light(t_list *lights, t_list *objects,
					t_object *closest_obj)
{
	t_vector	vec;
	t_color		color;
	t_light		*light;
	int			light_blocked;

	color = (t_color){0.0, 0.0, 0.0};
	while (lights)
	{
		light = (t_light *)lights->content;
		vec = ft_sub(closest_obj->intersection, light->pos);
		light->to_obj_dist = ft_length(vec);
		light->ray.o = light->pos;
		light->ray.dir = ft_unit_vector(vec);
		light_blocked = FALSE;
		ft_intersect_light(light, objects, closest_obj, &light_blocked);
		if (!light_blocked)
			color = ft_add_color(color, ft_add_light(light, closest_obj));
		lights = lights->next;
	}
	return (color);
}