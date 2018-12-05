/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cion <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:04:05 by cion              #+#    #+#             */
/*   Updated: 2017/11/27 17:04:08 by cion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	long out;
	long sign;

	out = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(*str) && *str != '\0')
	{
		out *= 10;
		out += (long)(*str - '0');
		str++;
	}
	if (((int)(out * sign) == 0 && out != 0) || (out < 0))
		out = (sign < 0) ? 0 : -1;
	return (int)(sign * out);
}
