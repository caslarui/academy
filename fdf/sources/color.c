/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:51:38 by cion              #+#    #+#             */
/*   Updated: 2018/01/23 16:51:43 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_1(t_env *world, int i, int j)
{
	if ((world->init[i][j].z < world->init[i][j + 1].z)
		|| (world->init[i][j].z > world->init[i][j + 1].z))
	{
		if (world->color == 0)
			world->line.color = 0x0646464;
		if (world->color == 1)
			world->line.color = 0x00000FF;
		if (world->color == 2)
			world->line.color = 0x000FF00;
		if (world->color == 3)
			world->line.color = 0x0FF0000;
	}
}

void	set_color_2(t_env *world, int i, int j)
{
	if ((world->init[i][j].z < world->init[i + 1][j].z)
		|| (world->init[i][j].z > world->init[i + 1][j].z))
	{
		if (world->color == 0)
			world->line.color = 0x0646464;
		if (world->color == 1)
			world->line.color = 0x00000FF;
		if (world->color == 2)
			world->line.color = 0x000FF00;
		if (world->color == 3)
			world->line.color = 0x0FF0000;
	}
}

int		get_red(int color)
{
	return ((int)(((color >> 16) & 0xFF)));
}

int		get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

int		get_blue(int color)
{
	return ((int)((color) & 0xFF));
}
