/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:48:18 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:58:05 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	ft_parse_sphere(t_list **objects, char **tab_str, t_section type, int *id)
{
	t_object	*obj;
	int			ret;

	ret = TRUE;
	if (!(ft_tabstrlen(tab_str) == 1))
		return (FALSE);
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = (*id)++;
	obj->type = type;
	obj->radius = 5.0;
	obj->color = (t_color){0.5, 0.0, 0.0};
	if (!ft_init_vector(&obj->pos, tab_str[0]))
		ret = FALSE;
	if (ret)
		ft_list_push_back(objects, ft_list_new(obj, sizeof(t_object)));
	ft_free_ptr((void **)&obj);
	return (ret);
}

int	ft_parse_plane(t_list **objects, char **tab_str, t_section type, int *id)
{
	t_object	*obj;
	int			ret;

	ret = TRUE;
	if (!(ft_tabstrlen(tab_str) == 2))
		return (FALSE);
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = (*id)++;
	obj->type = type;
	obj->color = (t_color){0.2, 1.0, 1.0};
	if (!ft_init_vector(&obj->pos, tab_str[0]) ||
		!ft_init_vector(&obj->rot, tab_str[1]))
		ret = FALSE;
	if (ret)
		ft_list_push_back(objects, ft_list_new(obj, sizeof(t_object)));
	ft_free_ptr((void **)&obj);
	return (ret);
}

int	ft_parse_cylinder(t_list **objects, char **tab_str, t_section type, int *id)
{
	t_object	*obj;

	if (!(ft_tabstrlen(tab_str) == 2))
		return (FALSE);
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = (*id)++;
	obj->type = type;
	if (!ft_init_vector(&obj->pos, tab_str[0]) ||
		!ft_init_vector(&obj->rot, tab_str[1]))
		return (FALSE);
	obj->radius = 3.0;
	obj->length = 1.0;
	obj->color = (t_color){0.7, 0.0, 1.0};
	ft_list_push_back(objects, ft_list_new(obj, sizeof(t_object)));
	ft_free_ptr((void **)&obj);
	return (TRUE);
}

int	ft_parse_cone(t_list **objects, char **tab_str, t_section type, int *id)
{
	t_object	*obj;

	if (!(ft_tabstrlen(tab_str) == 2))
		return (FALSE);
	obj = (t_object *)malloc(sizeof(t_object));
	obj->id = (*id)++;
	obj->type = type;
	if (!ft_init_vector(&obj->pos, tab_str[0]) ||
		!ft_init_vector(&obj->rot, tab_str[1]))
		return (FALSE);
	obj->radius = 0.50;
	obj->length = 0.50;
	obj->color = (t_color){0.7, 1.0, 0.0};
	ft_list_push_back(objects, ft_list_new(obj, sizeof(t_object)));
	ft_free_ptr((void **)&obj);
	return (TRUE);
}

int	ft_parse_object(t_list **objects, char *line)
{
	char		*str;
	char		*type;
	char		**tab_str;
	int			ret;
	static int	id = 0;

	type = line;
	ret = 0;
	str = ft_strchr(line, ':');
	type = ft_strsub(type, 0, str - type);
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (!ft_strcmp("Sphere", type))
		ret = ft_parse_sphere(objects, tab_str, SPHERE, &id);
	else if (!ft_strcmp("Plane", type))
		ret = ft_parse_plane(objects, tab_str, PLANE, &id);
	else if (!ft_strcmp("Cylinder", type))
		ret = ft_parse_cylinder(objects, tab_str, CYLINDER, &id);
	else if (!ft_strcmp("Cone", type))
		ret = ft_parse_cone(objects, tab_str, CONE, &id);
	ft_free_tabstr(tab_str);
	ft_free_ptr((void **)&str);
	ft_free_ptr((void **)&type);
	return (ret);
}
