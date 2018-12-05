/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:02:18 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 18:02:20 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_new;

	if ((int)len < 0 || !s)
		return (NULL);
	if (!(s_new = ft_strnew(len)))
		return (NULL);
	ft_strncpy(s_new, s + start, len);
	return (s_new);
}
