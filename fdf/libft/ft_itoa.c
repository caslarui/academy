/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:17:31 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:17:34 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digitcount(int n)
{
	size_t		l;

	l = 0;
	if (n <= 0)
		++l;
	while (n)
	{
		++l;
		n = n / 10;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	char		sign;
	size_t		l;
	char		*s;

	sign = 1;
	if (n < 0)
		sign = -1;
	l = ft_digitcount(n);
	s = ft_strnew(l);
	if (!s)
		return (NULL);
	while (l)
	{
		*(s + (--l)) = sign * (n % 10) + 48;
		n = n / 10;
	}
	if (sign == -1)
		*s = '-';
	return (s);
}
