/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user00 <user00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:39:39 by cion              #+#    #+#             */
/*   Updated: 2018/05/02 18:41:25 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listadd(t_gnl *last, t_gnl *new)
{
	if (last != NULL && new != NULL)
	{
		last->next = new;
		new->prev = last;
	}
}

t_gnl	*ft_newlst(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->c = NULL;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

int		helper(char **line, t_gnl *buffsave)
{
	char *s;

	s = ft_strchr(buffsave->c, '\n');
	if (s != NULL)
	{
		*s = '\0';
		*line = ft_strdup((buffsave->c));
		buffsave->c = ft_strdup(s + 1);
		return (1);
	}
	if (ft_strlen((buffsave->c)) > 0)
	{
		*line = ft_strdup((buffsave->c));
		*(buffsave)->c = '\0';
		return (1);
	}
	return (0);
}

t_gnl	*listfunction(t_gnl *buffsave, int fd)
{
	while ((int)buffsave->fd < fd && buffsave)
	{
		if (!buffsave->next)
			ft_listadd(buffsave, ft_newlst(fd));
		buffsave = buffsave->next;
		if ((int)buffsave->fd == fd)
			return (buffsave);
	}
	while ((int)buffsave->fd > fd && buffsave)
	{
		buffsave = buffsave->prev;
		if ((int)buffsave->fd == fd)
			return (buffsave);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*buffsave;
	char			buf[BUFF_SIZE + 1];
	int				check;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0 || fd >= MAX_FD)
		return (-1);
	if (buffsave && (int)buffsave->fd != fd && fd)
		buffsave = listfunction(buffsave, fd);
	if (buffsave == NULL)
		buffsave = ft_newlst(fd);
	*line = 0;
	while ((check = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[check] = '\0';
		buffsave->c = ft_strjoinfree(buffsave->c, buf, 1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (check < 0)
		return (-1);
	return (helper(line, buffsave));
}
