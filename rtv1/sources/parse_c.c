/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:02:27 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:57:55 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_cam	*ft_init_cam(void)
{
	t_cam	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		perror("error : cam memory allocation");
	return (cam);
}

int				ft_parse_camera(t_scene *sc, char *line)
{
	char	*str;
	char	**tab_str;

	if (!(sc->cam = ft_init_cam()))
		return (FALSE);
	str = ft_strchr(line, ':');
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (ft_tabstrlen(tab_str) == 2)
	{
		if (!ft_init_vector(&sc->cam->pos, tab_str[0]) ||
			!ft_init_vector(&sc->cam->rot, tab_str[1]))
			return (FALSE);
		ft_free_tabstr(tab_str);
		ft_free_ptr((void **)&str);
		return (TRUE);
	}
	ft_free_ptr((void **)&str);
	return (FALSE);
}