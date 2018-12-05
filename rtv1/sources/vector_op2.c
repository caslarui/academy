/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:56:47 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:56:50 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	ft_neg(t_vector v)
{
	return ((t_vector){-v.x, -v.y, -v.z});
}

t_vector	ft_add(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	ft_sub(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	ft_mult(t_vector v, double r)
{
	return ((t_vector){v.x * r, v.y * r, v.z * r});
}

t_vector	ft_div(t_vector v, double r)
{
	return ((t_vector){v.x / r, v.y / r, v.z / r});
}
