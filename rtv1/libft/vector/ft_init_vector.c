/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:13:26 by user00            #+#    #+#             */
/*   Updated: 2018/05/20 12:43:42 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_init_vector(t_vector *v, char *str)
{
    char    **tab_str;
    int     ret;

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