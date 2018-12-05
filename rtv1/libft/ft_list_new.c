/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:37:56 by user00            #+#    #+#             */
/*   Updated: 2018/05/13 10:39:02 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_list_new(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		if (content)
		{
			list->content_size = content_size;
			list->content = ft_memalloc(content_size);
			ft_memcpy(list->content, (void *)content, content_size);
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
		list->next = NULL;
	}
	return (list);
}