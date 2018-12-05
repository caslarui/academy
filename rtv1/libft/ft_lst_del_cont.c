/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_cont.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:40:11 by user00            #+#    #+#             */
/*   Updated: 2018/05/13 10:34:02 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_del_content(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
	{
		free(content);
		content = NULL;
	}
	content_size = 0;
}