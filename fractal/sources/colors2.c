/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:10:18 by cion              #+#    #+#             */
/*   Updated: 2018/03/14 16:48:52 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void    color6(t_img *data)
{
    data->colors[126] = 0x6ad9;
    data->colors[127] = 0x7412;
    data->colors[128] = 0xffdf;
    data->colors[129] = 0x07ef;
    data->colors[130] = 0x4416;
    data->colors[131] = 0xd5b1;
    data->colors[132] = 0x0410;
    data->colors[133] = 0xddfb;
    data->colors[134] = 0xfb08;
    data->colors[135] = 0x471a;
    data->colors[136] = 0xec1d;
    data->colors[137] = 0xd112;
    data->colors[138] = 0xd112;
    data->colors[139] = 0xffff;
    data->colors[140] = 0xf7be;
    data->colors[141] = 0xffe0;
    data->colors[142] = 0x9e66;
    data->colors[143] = 0xffff;
}

void    color_init(t_img *data)
{
    color1(data);
    color2(data);
    color3(data);
    color4(data);
    color5(data);
    color6(data);
}

void    prnt_fractal(t_img *data)
{
    if (strcmp("Mandelbrot", data->name) == 0)
        mandelbrot(data);
    else if (strcmp("Julia", data->name) == 0)
        Julia(data);
    else if (strcmp("Newton", data->name) == 0)
        Newton(data);
    else ft_putendl("Eroare !!! Denumirea fractalului este incorecta");
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}