/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:52:38 by cion              #+#    #+#             */
/*   Updated: 2018/01/23 16:52:41 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_func(int key_code, t_env *world)
{
	ft_putendl(ft_itoa(key_code));
	if (key_code == 53)
	{
		exit(0);
	}
	if (key_code == 15)
		world->color = 1;
	if (key_code == 5)
		world->color = 2;
	if (key_code == 11)
		world->color = 3;
	if (key_code == 29)
		world->color = 0;
	event_1(key_code, world);
	event_2(key_code, world);
	if (key_code == 15)
		set_default(world);
	translate(world);
	return (0);
}

void	event_1(int key_code, t_env *world)
{
	if (key_code == 24)
		world->scale += 1;
	if (key_code == 27)
	{
		if (world->scale != 1)
			world->scale -= 1;
	}
	if (key_code == 0)
		world->x_offset -= 2;
	if (key_code == 2)
		world->x_offset += 2;
	if (key_code == 1)
		world->y_offset -= 2;
	if (key_code == 13)
		world->y_offset += 2;
	if (key_code == 45)
		world->scale_z++;
	if (key_code == 46)
		world->scale_z--;
}

void	event_2(int key_code, t_env *world)
{
	if (key_code == 50)
		world->projection = 0;
	if (key_code == 6)
		world->projection = 1;
	if (key_code == 7)
		world->projection = 2;
	if (key_code == 12)
		x_rotation(world, 0.019);
	if (key_code == 14)
		x_rotation(world, -0.019);
	if (key_code == 126)
		z_rotation(world, 0.019);
	if (key_code == 125)
		z_rotation(world, -0.019);
	if (key_code == 123)
		y_rotation(world, -0.019);
	if (key_code == 124)
		y_rotation(world, 0.019);
}

void	set_default(t_env *world)
{
	int i;
	int j;

	i = 0;
	world->scale = 30;
	world->scale_z = 2;
	world->x_offset = WIDTH / 2;
	world->y_offset = HEIGHT / 2;
	while (i < world->row)
	{
		j = 0;
		while (j < world->col)
		{
			world->pts[i][j] = world->init[i][j];
			j++;
		}
		i++;
	}
}
