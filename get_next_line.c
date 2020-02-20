/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:34:32 by eestela           #+#    #+#             */
/*   Updated: 2020/02/20 18:17:52 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_findlink(int fd, t_struc **start, t_struc **link)
{
	t_struc				*tmp;
	t_struc				*starter;

	starter = *start;
	tmp = *start;
	while (tmp)
	{
		if (tmp->fd == fd && (*link = tmp))
			return (1);
		tmp = tmp->next;
	}
	tmp = NULL;
	if (!(tmp = malloc(sizeof(t_struc))))
		return (-1);
	tmp->fd = fd;
	if (!(tmp->cont = ft_strdup("")))
		return (-2);
	tmp->next = starter;
	*start = tmp;
	*link = tmp;
	return (1);
}

int				ft_place(t_struc *link, char **line, int check)
{
	int			r;
	char		*tmp;

	r = 0;
	while (link->cont[r] != '\n' && link->cont[r])
		r++;
	tmp = *line;
	if (!(*line = ft_substr(link->cont, 0, r)))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	tmp = link->cont;
	if (!(link->cont = ft_substr(link->cont, r + 1, ft_strlen(link->cont))))
	{
		free(tmp);
		return (-2);
	}
	free(tmp);
	return (check);
}

int				ft_gnl_read(int fd, char **line, t_struc *link)
{
	char				*buf;
	int					r;
	char				*tmp;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(link->cont, '\n') && (r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = 0;
		tmp = link->cont;
		if (!(link->cont = ft_strjoin(link->cont, buf)))
		{
			free(buf);
			return (-2);
		}
		free(tmp);
	}
	free(buf);
	if (r < 0)
		return (r);
	return (ft_place(link, line, r));
}

int				ft_free_gnl(int fd, t_struc **start, int r)
{
	t_struc		*link;
	t_struc		*tmp;

	link = *start;
	tmp = *start;
	if (r <= 0)
	{
		while (fd != link->fd)
			link = link->next;
		if (link == tmp)
			*start = link->next;
		else
		{
			while (tmp->next != link)
				tmp = tmp->next;
			tmp->next = link->next;
		}
		if (r != -2)
			free(link->cont);
		free(link);
	}
	if (r < 0)
		return (-1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_struc		*start;
	t_struc				*link;
	int					r;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || !(*line = ft_strdup("")))
		return (-1);
	r = ft_findlink(fd, &start, &link);
	if (r < 0)
		return (ft_free_gnl(fd, &start, r));
	r = ft_gnl_read(fd, line, link);
	if (r < 0)
		return (ft_free_gnl(fd, &start, r));
	if (r == 0)
		return (ft_free_gnl(fd, &start, 0));
	return (1);
}
