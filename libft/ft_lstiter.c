/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:22:09 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:22:11 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current_lst;
	t_list	*next_lst;

	if (!lst || !(f))
		return ;
	current_lst = lst;
	while (current_lst != NULL)
	{
		next_lst = current_lst->next;
		f(current_lst);
		current_lst = next_lst;
	}
}
