/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 09:45:51 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:51 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		ft_get_distance(t_op *op)
{
	op->t1 = (-op->b + sqrt(op->delta)) / (2 * op->a);
	op->t2 = (-op->b - sqrt(op->delta)) / (2 * op->a);
	op->t = (op->t1 < op->t2) ? op->t1 : op->t2;
}

int			ft_intersect_object(t_ray ray, t_object *obj)
{
	if (obj->type == SPHERE)
	{
		if (ft_intersect_sphere(ray, obj))
			return (TRUE);
	}
	if (obj->type == PLANE)
	{
		if (ft_intersect_plane(ray, obj))
			return (TRUE);
	}
	if (obj->type == CYLINDER)
	{
		if (ft_intersect_cylinder(ray, obj))
			return (TRUE);
	}
	if (obj->type == CONE)
	{
		if (ft_intersect_cone(ray, obj))
			return (TRUE);
	}
	return (FALSE);
}

t_object	*ft_get_closest_object(t_ray ray, t_list *objects)
{
	t_object	*i_obj;
	t_object	*obj;
	double		dist;
	double		tmp_dist;

	dist = 99999999999;
	obj = NULL;
	while (objects)
	{
		i_obj = (t_object *)objects->content;
		if (ft_intersect_object(ray, i_obj))
		{
			tmp_dist = ft_squared_length(ft_sub(i_obj->intersection, ray.o));
			if (tmp_dist < dist)
			{
				dist = tmp_dist;
				obj = i_obj;
			}
		}
		objects = objects->next;
	}
	return (obj);
}
