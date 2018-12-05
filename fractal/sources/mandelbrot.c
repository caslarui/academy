/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:51:00 by cion              #+#    #+#             */
/*   Updated: 2018/03/14 16:07:16 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static  void mandel_calc(t_img *data, int x, int y)
{
    data->pr = 1.5 * (x - WIDTH / 2) / (0.5 * data->zoom * WIDTH) + data->x;
    data->pi = (y - HEIGHT / 2) / (0.5 * data->zoom * HEIGHT) + data->y;
    data->newRe = data->newIm = data->oldRe = data->oldIm = 0;
}

static  void mandel_swap(t_img *data)
{
    data->oldRe = data->newRe;
    data->oldIm = data->newIm;
    data->newRe = sqr(data->oldRe) - sqr(data->oldIm) + data->pr;
    data->newIm = 2 * data->oldRe * data->oldIm + data->pi;
}

void mandelbrot(t_img *data)
{
    int x;
    int y;
    int i;
    unsigned int color;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < HEIGHT)
        {
            mandel_calc(data, x, y);
            i = -1;
            while (++i < data->maxIt)
            {
                mandel_swap(data);
                if((sqr(data->newRe) + sqr(data->newIm)) > 4) break;
            }
            color = data->colors[i];
            if (i < data->maxIt)
                p_t_img(data, color, x, y);
            else
                p_t_img(data, color, x, y);
        }
    }
}