/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:02:06 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:17 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void		ft_put_pixel_img(t_scene *sc, t_point_i p, t_color color)
{
	int	i;

	i = p.x * 4 + p.y * sc->img->size_line;
	sc->img->data[i] = (unsigned char)(color.b * 255);
	sc->img->data[++i] = (unsigned char)(color.g * 255);
	sc->img->data[++i] = (unsigned char)(color.r * 255);
}

t_color			ft_ray_trace(t_scene *sc, t_ray ray)
{
	t_object	*closest_obj;
	t_color		color;

	color = (t_color){0.0, 0.0, 0.0};
	closest_obj = ft_get_closest_object(ray, sc->objects);
	if (closest_obj)
		color = ft_ray_trace_light(sc->lights, sc->objects, closest_obj);
	return (ft_unit_color(color));
}

static void		ft_draw_img(t_scene *sc)
{
	t_ray		ray;
	t_point_i	p;

	ft_cam_new(sc->cam);
	p.y = 0;
	while (p.y < sc->height)
	{
		p.x = 0;
		while (p.x < sc->width)
		{
			ray.o = sc->cam->pos;
			ray.dir = ft_unit_vector(ft_cam_get_dir(sc->cam, p, sc->width,
				sc->height));
			ft_put_pixel_img(sc, p, ft_ray_trace(sc, ray));
			++p.x;
		}
		++p.y;
	}
}

void			ft_draw_window(t_scene *sc)
{
	sc->img->img_ptr = mlx_new_image(sc->mlx, sc->width, sc->height);
	sc->img->data = mlx_get_data_addr(sc->img->img_ptr,
		&(sc->img->bpp), &(sc->img->size_line), &(sc->img->endian));
	ft_draw_img(sc);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img->img_ptr, 0, 0);
	mlx_destroy_image(sc->mlx, sc->img->img_ptr);
}