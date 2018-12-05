/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:34:34 by user00            #+#    #+#             */
/*   Updated: 2018/03/14 16:46:07 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void    Newton(t_img *data)
{
    int i;
    int x;
    int y;
    double tmp;
    unsigned int color;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            data->newRe = (x - WIDTH) / (data->zoom * WIDTH) + data->x;
            data->newIm = (y - HEIGHT) / (data->zoom * HEIGHT) + data->y;
            i = 0;
            tmp = 1.0;
            while (tmp > 0.000001 && ++i < data->maxIt)
            {
                data->oldRe = data->newRe;
                data->oldIm = data->newIm;
                tmp = (sqr(data->newRe) + sqr(data->newIm)) *
                                 (sqr(data->newRe) + sqr(data->newIm));
                data->newRe = (2 * data->newRe * tmp + sqr(data->newRe) - 
                                sqr(data->newIm)) / (3.0 * tmp);
                data->newIm = (2 * data->newIm * (tmp - data->oldRe)) /
                                 (3.0 * tmp);
                tmp = (data->newRe - data->oldRe) * 
                (data->newRe - data->oldRe) + (data->newIm - data->oldIm) *
                            (data->newIm - data->oldIm);
            }
            color = data->colors[i];
            if (i < data->maxIt)
                p_t_img(data, color, x, y);
            else
                p_t_img(data, color, x, y);
        }
    }
}