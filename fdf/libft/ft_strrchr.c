/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:59:57 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:59:59 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c_tmp;
	char			*s_tmp;
	size_t			l;

	s_tmp = ft_strchr(s, 0);
	l = ft_strlen(s) + 1;
	c_tmp = (unsigned char)c;
	while (l--)
	{
		if (*s_tmp == c_tmp)
			return (s_tmp);
		--s_tmp;
	}
	return (NULL);
}
