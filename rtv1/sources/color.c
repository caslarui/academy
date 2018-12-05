/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:57:49 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:14 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color		ft_mult_color(t_color c, double r)
{
	return ((t_color){c.r * r, c.g * r, c.b * r});
}

t_color		ft_cross_color(t_color a, t_color b)
{
	return ((t_color){a.g * b.b - a.b * b.g,
		a.b * b.r - a.r * b.b,
		a.r * b.g - a.g * b.r});
}

t_color		ft_add_color(t_color a, t_color b)
{
	return ((t_color){a.r += b.r, a.g += b.g, a.b += b.b});
}

t_color		ft_unit_color(t_color c)
{
	t_color		color;

	color.r = (c.r > 1.0) ? 1.0 : c.r;
	color.g = (c.g > 1.0) ? 1.0 : c.g;
	color.b = (c.b > 1.0) ? 1.0 : c.b;
	return (color);
}