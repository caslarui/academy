/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:23:22 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:23:25 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->next = (t_list *)NULL;
	new_list->content = (void *)NULL;
	new_list->content_size = 0;
	if ((content == NULL) || (content_size <= 0))
		return (new_list);
	if (!(new_list->content = ft_memalloc(content_size)))
		return ((t_list*)(NULL));
	ft_memcpy(new_list->content, content, content_size);
	new_list->content_size = content_size;
	return (new_list);
}
