/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:20:27 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:20:29 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
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
