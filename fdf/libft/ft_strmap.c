/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:53:41 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:53:43 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*s_new;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		if (!(s_new = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			s_new[i] = (*f)(s[i]);
			i++;
		}
		return (s_new);
	}
	return (NULL);
}
