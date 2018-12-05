/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:27:27 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:09 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		ft_cam_new(t_cam *cam)
{
	t_vector	dir;

	cam->up = (t_vector){0.0, 1.0, 0.0};
	cam->vp_dist = 1.0;
	cam->vp_height = 0.35;
	cam->vp_width = 0.5;
	dir = ft_sub(cam->rot, cam->pos);
	dir = ft_unit_vector(dir);
	cam->right = ft_cross(cam->up, dir);
	cam->up = ft_cross(dir, cam->right);
	cam->vp_up_left = ft_add(cam->pos,
		ft_sub(ft_add(ft_mult(dir, cam->vp_dist),
		ft_mult(cam->up, cam->vp_height / 2.0)),
		ft_mult(cam->right, cam->vp_width / 2.0)));
}

t_vector	ft_cam_get_dir(t_cam *cam, t_point_i p, int width, int height)
{
	t_point_f	indent;
	t_vector	right;
	t_vector	up;
	t_vector	vp_up_left;
	t_vector	dir;

	indent.x = cam->vp_width / (double)width;
	indent.y = cam->vp_height / (double)height;
	right = ft_mult(ft_mult(cam->right, indent.x), p.x);
	up = ft_mult(ft_mult(cam->up, indent.y), p.y);
	vp_up_left = ft_add(cam->vp_up_left, ft_sub(right, up));
	dir = ft_sub(vp_up_left, cam->pos);
	return (dir);
}