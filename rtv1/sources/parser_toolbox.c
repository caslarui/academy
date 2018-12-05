/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:56:03 by user00            #+#    #+#             */
/*   Updated: 2018/05/22 15:56:13 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	ft_init_vector(t_vector *v, char *str)
{
	char	**tab_str;
	int		ret;

	ret = TRUE;
	tab_str = ft_strsplit(str, ' ');
	if (!(ft_tabstrlen(tab_str) == 3))
		ret = FALSE;
	if (ret)
	{
		v->x = (double)ft_atoi(tab_str[0]);
		v->y = (double)ft_atoi(tab_str[1]);
		v->z = (double)ft_atoi(tab_str[2]);
	}
	ft_free_tabstr(tab_str);
	return (ret);
}
