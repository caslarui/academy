/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjustments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:59:53 by cion              #+#    #+#             */
/*   Updated: 2018/03/14 16:46:03 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_img       *initialize(void)
{
    t_img *data;

    data = (t_img *)malloc(sizeof(t_img));
    data->zoom = 0.7;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "fractal");
    data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
    data->x = 0;
    data->y = 0;
    data->pr = 0;
    data->pi = 0;
    data->cIm = 0.15;
    data->cRe = -0.8;
    data->maxIt = 300;
    data->newIm = 0;
    data->newRe = 0;
    data->oldRe = 0;
    data->oldIm = 0;
    return(data);
}

static int		get_red(int color)
{
	return ((int)(((color >> 16) & 0xFF)));
}

static int		get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

static int		get_blue(int color)
{
	return ((int)((color) & 0xFF));
}

void    p_t_img(t_img *data, int color, int x, int y)
{
    int p;

    if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
    {
        data->px = mlx_get_data_addr(data->img, &p, &p, &p);
        p = (WIDTH * y + x) * 4;
        data->px[p] = get_red(color);
        data->px[p + 1] = get_green(color);
        data->px[p + 2] = get_blue(color);
    }
}
void    img_clear(t_img *data)
{
    int p;

    data->px = mlx_get_data_addr(data->img, &p, &p, &p);
    ft_bzero(data->px, 4 * WIDTH * HEIGHT);
}

