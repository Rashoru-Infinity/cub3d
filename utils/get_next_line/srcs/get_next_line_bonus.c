/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:55:53 by khagiwar          #+#    #+#             */
/*   Updated: 2021/03/02 03:36:34 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdbool.h>

void		remove_gnlist(int fd, t_gnlist **head, t_gnlist *prev)
{
	t_gnlist *curr;

	if (!head)
		return ;
	curr = *head;
	if (curr->fd == fd)
	{
		if (prev)
			prev->next = curr->next;
		else
			*head = curr->next;
		free(curr->str);
		free(curr);
	}
	else if (curr->next)
		remove_gnlist(fd, &(curr->next), curr);
}

t_gnlist	*get_gnlist(int fd, t_gnlist **head)
{
	t_gnlist *curr;

	curr = *head;
	if (!curr)
	{
		if (!(curr = (t_gnlist *)malloc(sizeof(t_gnlist))))
			return (NULL);
		*curr = (t_gnlist){NULL, NULL, fd};
		*head = curr;
	}
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		if (!(curr->next))
		{
			if (!(curr->next = (t_gnlist *)malloc(sizeof(t_gnlist))))
				break ;
			*(curr->next) = (t_gnlist){NULL, NULL, fd};
		}
		curr = curr->next;
	}
	return (NULL);
}

int			get_next_line(int fd, char **line)
{
	static t_gnlist	*store;
	t_scanner		in;
	int				status;
	t_gnlist		*curr;

	status = normal;
	in.fd = fd;
	in.buf = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ft_close(&store, line, &in, error));
	if (!(curr = get_gnlist(fd, &store)))
		return (ft_close(&store, line, &in, error));
	if (!(in.buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ft_close(&store, line, &in, error));
	while ((in.rdsz = read(fd, in.buf, BUFFER_SIZE)) > 0)
	{
		in.buf[in.rdsz] = 0x1a;
		if ((status = ft_strdiv(&store, &in, line)) == ln)
			return (ft_close(&store, line, &in, ln));
		if (status == error)
			return (ft_close(&store, line, &in, error));
	}
	if (in.rdsz < 0)
		status = error;
	return (ft_close(&store, line, &in, status));
}

int			ft_strdiv(t_gnlist **store, t_scanner *in, char **line)
{
	char		*line_break;
	t_gnlist	*lst;

	lst = get_gnlist(in->fd, store);
	if (in->rdsz == 0)
		line_break = ft_strln(lst->str);
	else if (ft_strjoinln(&(lst->str), in->buf, &line_break) == error)
		return (ft_close(store, line, in, error));
	if (!line_break && in->rdsz > 0)
		return (normal);
	if (!(*line = (char *)malloc(sizeof(char) *
	(my_strlen(lst->str, '\n') + 1))))
		return (ft_close(store, line, in, error));
	my_memccpy(*line, lst->str, '\n', my_strlen(lst->str, '\n'));
	(*line)[my_strlen(lst->str, '\n')] = '\0';
	if (line_break)
	{
		my_memmove(lst->str, &line_break[1],
		my_strlen(&line_break[1], 0x1a) + 1);
		if (in->rdsz > 0)
			return (ln);
		return (normal);
	}
	return (ft_close(store, line, in, end));
}

int			ft_close(t_gnlist **store, char **line, t_scanner *in, int status)
{
	free(in->buf);
	(*in).buf = NULL;
	if (status == ln)
		return (normal);
	if (status == error || status == end)
	{
		remove_gnlist(in->fd, store, NULL);
		return (status);
	}
	(*in).rdsz = 0;
	return (ft_strdiv(store, in, line));
}
