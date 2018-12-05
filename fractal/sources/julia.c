/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:26:35 by cion              #+#    #+#             */
/*   Updated: 2018/03/13 17:37:52 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void julia_calc_1(t_img *data, int x, int y)
{
    data->newRe = 1.5 * (x - WIDTH / 2) / (0.5 * data->zoom * WIDTH) + data->x;
    data->newIm = (y - HEIGHT / 2) / (0.5 * data->zoom * HEIGHT) + data->y;
}

static void julia_swap(t_img *data)
{
    data->oldRe = data->newRe;
    data->oldIm = data->newIm;
    data->newRe = sqr(data->oldRe) - sqr(data->oldIm) + data->cRe;
    data->newIm = 2 * data->oldRe * data->oldIm + data->cIm;
}

void    Julia(t_img *data)
{
    int i;
    int x;
    int y;
    unsigned int color;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            julia_calc_1(data, x, y);
            i = -1;
            while (++i < data->maxIt)
            {
                julia_swap(data);
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