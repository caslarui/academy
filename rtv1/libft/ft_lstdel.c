/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:20:27 by cion              #+#    #+#             */
/*   Updated: 2018/05/20 12:55:59 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_del(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;
	t_list	*next_lst;

	if (!alst || !del)
		return ;
	lst = *alst;
	while (lst != NULL)
	{
		next_lst = lst->next;
		ft_lstdelone(&lst, del);
		lst = next_lst;
	}
	*alst = NULL;
}
