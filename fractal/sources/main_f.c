/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:49:10 by cion              #+#    #+#             */
/*   Updated: 2018/03/14 15:42:48 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int main (int ac, char **av)
{
    t_img *data;

    data = initialize();
    data->name = ft_strdup(av[--ac]);
    color_init(data);
    mlx_mouse_hook(data->win, my_mouse_func, data);
    mlx_key_hook(data->win, my_key_func, data);
    prnt_fractal(data);
    mlx_loop(data->mlx);
    return (0);
}