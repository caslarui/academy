/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:21:10 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:58:19 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			main(int argc, char *argv[])
{
	t_scene		*sc;
	int			fd;
	char		c;

	if (argc != 2)
	{
		ft_putstr("error : no arguments\n");
		return (FALSE);
	}
	if (!(fd = open(argv[1], O_RDONLY)) || read(fd, &c, 0) == -1)
	{
		ft_putstr("error : not a valid file\n");
		return (FALSE);
	}
	if (!(sc = ft_new_scene(fd)))
	{
		ft_destroy_scene(sc);
		return (FALSE);
	}
	mlx_key_hook(sc->win, ft_key_hook, sc);
	mlx_expose_hook(sc->win, ft_expose_hook, sc);
	mlx_loop(sc->mlx);
	return (FALSE);
}