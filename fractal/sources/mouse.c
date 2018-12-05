/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:10:55 by cion              #+#    #+#             */
/*   Updated: 2018/03/13 17:56:39 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int my_mouse_func(int k, int x, int y, t_img *data)
{
    (void)y;
    (void)x;
    if (k == 4)
    {
        data->zoom *= 0.8;
        data->maxIt += 20;
    }
    if (k == 5)
    {
        data->zoom /= 0.5;
        data->maxIt -= 20;
    }
    prnt_fractal(data); 
    return (0);
}