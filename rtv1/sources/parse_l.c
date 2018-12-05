/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:41:12 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:58:00 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_parse_light(t_list **lights, char *line)
{
	char		*str;
	char		**tab_str;
	t_light		*light;
	int			ret;

	ret = TRUE;
	str = ft_strchr(line, ':');
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	light = (t_light *)malloc(sizeof(t_light));
	if (!(ft_tabstrlen(tab_str) == 1))
		ret = FALSE;
	if (ret == TRUE)
	{
		if (!(ft_init_vector(&light->pos, tab_str[0])))
			ret = FALSE;
		else
			ft_list_push_back(lights, ft_list_new(light, sizeof(t_light)));
	}
	ft_free_tabstr(tab_str);
	ft_free_ptr((void **)&str);
	ft_free_ptr((void **)&light);
	return (ret);
}