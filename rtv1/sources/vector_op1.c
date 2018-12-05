/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:56:24 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:56:33 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		ft_length(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double		ft_squared_length(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double		ft_dot(t_vector vec_1, t_vector vec_2)
{
	return (vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z);
}

t_vector	ft_cross(t_vector vec_1, t_vector vec_2)
{
	return ((t_vector){vec_1.y * vec_2.z - vec_1.z * vec_2.y,
		vec_1.z * vec_2.x - vec_1.x * vec_2.z,
		vec_1.x * vec_2.y - vec_1.y * vec_2.x});
}

t_vector	ft_unit_vector(t_vector v)
{
	return (t_vector)(ft_div(v, ft_length(v)));
}
