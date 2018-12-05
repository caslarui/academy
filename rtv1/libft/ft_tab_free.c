/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:15:41 by user00            #+#    #+#             */
/*   Updated: 2018/05/13 10:34:25 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_free_tabstr(char **tab_str)
{
	int		i;

	i = 0;
	while (tab_str[i])
	{
		ft_free_ptr((void **)&tab_str[i]);
		++i;
	}
	ft_free_ptr((void **)&tab_str);
}