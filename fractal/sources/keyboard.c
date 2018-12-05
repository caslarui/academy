/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:23:09 by cion              #+#    #+#             */
/*   Updated: 2018/03/14 15:27:56 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int my_key_func(int k, t_img *data)
{
    ft_putendl(ft_itoa(k));
    if (k == KEY_DOWN)
        data->y +=0.050 / data->zoom;
    if (k == KEY_UP)
        data->y -=0.050 / data->zoom;
    if (k == KEY_LEFT)
        data->x -=0.050 / data->zoom;
    if (k == KEY_RIGHT)
        data->x +=0.050 / data->zoom;
    if (k == KEY_ESCAPE)
    {
        mlx_destroy_window(data->mlx,data->win);
        free(data);
        exit(0);
    }
    prnt_fractal(data); 
    return(0);
}

