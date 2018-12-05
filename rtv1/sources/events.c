/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:18:14 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:20 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int     ft_expose_hook(t_scene *sc)
{
    ft_draw_window(sc);
    return (0);
}

int     ft_key_hook(int keycode, t_scene *sc)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(sc->mlx, sc->win);
        ft_destroy_scene(sc);
        exit(EXIT_SUCCESS);
    }
    ft_draw_window(sc);
    return (FALSE);
}