/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:25:49 by cion              #+#    #+#             */
/*   Updated: 2018/01/23 17:25:53 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int argc, int fd)
{
	if (argc != 2)
	{
		ft_putendl("Numar invalid de argumente");
		exit(0);
	}
	if (fd == -1)
	{
		ft_putendl("Lipseste fisierul");
		exit(0);
	}
}
