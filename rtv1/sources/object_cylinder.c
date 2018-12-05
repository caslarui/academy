/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 12:53:17 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:35 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void		ft_compute_delta_cylinder(t_ray ray, t_object *obj, t_op *op)
{
	op->v = ft_unit_vector(obj->rot);
	op->x = ft_sub(ray.o, obj->pos);
	op->dv = ft_dot(ray.dir, op->v);
	op->xv = ft_dot(op->x, op->v);
	op->a = ft_dot(ray.dir, ray.dir) - (op->dv * op->dv);
	op->b = (ft_dot(ray.dir, op->x) - (op->dv * op->xv)) * 2.0;
	op->c = ft_dot(op->x, op->x) - (op->xv * op->xv) -
		(obj->radius * obj->radius);
	op->delta = (op->b * op->b) - (4 * op->a * op->c);
}

int				ft_intersect_cylinder(t_ray ray, t_object *obj)
{
	t_op	op;

	ft_compute_delta_cylinder(ray, obj, &op);
	if (op.delta >= 0)
	{
		ft_get_distance(&op);
		obj->intersection = ft_add(ray.o, ft_mult(ray.dir, op.t));
		op.m = ft_dot(ray.dir, ft_mult(op.v, op.t)) + ft_dot(op.x, op.v);
		obj->normal = ft_unit_vector(
			ft_sub(ft_add(ft_mult(ray.dir, op.t), op.x), ft_mult(op.v, op.m)));
		return (TRUE);
	}
	return (FALSE);
}