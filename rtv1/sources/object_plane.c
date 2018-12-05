/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:38:40 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:38 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_intersect_plane(t_ray ray, t_object *obj)
{
	t_op	op;

	op.d = ray.dir;
	op.v = ft_unit_vector(obj->rot);
	op.x = ft_sub(ray.o, obj->pos);
	op.dv = ft_dot(op.d, op.v);
	if (op.dv == 0)
		return (FALSE);
	op.xv = ft_dot(op.x, op.v);
	op.t = -op.xv / op.dv;
	if (op.t < 0)
		return (FALSE);
	obj->intersection = ft_add(ray.o, ft_mult(op.d, op.t));
	obj->normal = (op.dv < 0) ? op.v : ft_neg(op.v);
	return (TRUE);
}