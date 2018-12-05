/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:10:22 by user00            #+#    #+#             */
/*   Updated: 2018/05/13 10:35:18 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int ft_tabstrlen(char **tab_str)
{
    int i;

    i = 0;
    while(tab_str[i])
    {
        ++i;
    }
    return(i);
}