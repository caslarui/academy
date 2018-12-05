/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:50:30 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:50:32 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	len;
	int	i;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen((const char *)s);
		i = 0;
		while (i < len)
		{
			(*f)(s);
			s++;
			i++;
		}
	}
}