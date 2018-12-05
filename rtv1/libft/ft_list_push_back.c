/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:36:23 by user00            #+#    #+#             */
/*   Updated: 2018/05/13 10:40:31 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_push_back(t_list **begin_list, t_list *elem)
{
	t_list	*list;

	list = *begin_list;
	if (!list)
	{
		list = elem;
		*begin_list = list;
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
}