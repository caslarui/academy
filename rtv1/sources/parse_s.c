/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:31:11 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:58:11 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int		ft_set_scene(t_scene *sc, char *line, t_section *section)
{
	int			ret;
	static int	nb_cam = 0;

	ret = 1;
	if (*section == CAMERA)
	{
		if (nb_cam == 0)
		{
			ret = ft_parse_camera(sc, line);
			++nb_cam;
		}
		else
		{
			ft_putstr_fd("error : too much cameras\n", 2);
			ret = 0;
		}
	}
	else if (*section == LIGHT)
		ret = ft_parse_light(&sc->lights, line);
	else if (*section == SPHERE || *section == PLANE ||
				*section == CYLINDER || *section == CONE)
		ret = ft_parse_object(&sc->objects, line);
	return (ret);
}

static void		ft_get_section(char *line, t_section *section)
{
	if (!ft_strncmp(line, "Camera:", 7))
		*section = CAMERA;
	else if (!ft_strncmp(line, "Light:", 6))
		*section = LIGHT;
	else if (!ft_strncmp(line, "Sphere:", 7))
		*section = SPHERE;
	else if (!ft_strncmp(line, "Plane:", 6))
		*section = PLANE;
	else if (!ft_strncmp(line, "Cylinder:", 9))
		*section = CYLINDER;
	else if (!ft_strncmp(line, "Cone:", 5))
		*section = CONE;
	else
		*section = NONE;
}

int				ft_parse_scene(t_scene *sc, int fd)
{
	char		*line;
	t_section	section;

	while (get_next_line(fd, &line))
	{
		ft_get_section(line, &section);
		if (!ft_set_scene(sc, line, &section))
		{
			ft_free_ptr((void **)&line);
			return (FALSE);
		}
		ft_free_ptr((void **)&line);
	}
	ft_free_ptr((void **)&line);
	if (!sc->cam)
	{
		ft_putstr_fd("error : no camera in scene\n", 2);
		return (FALSE);
	}
	return (TRUE);
}