/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:27:58 by eestela           #+#    #+#             */
/*   Updated: 2019/12/04 15:48:24 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_struc		*ft_findlst(t_struc **start, int fd)
{
	t_struc *lst;

	lst = *start;
	if (!lst)
	{
		if (!(lst = (t_struc*)malloc(sizeof(t_struc))))
			return (NULL);
		lst->cont = ft_strdup("");
		lst->next = *start;
		lst->fd = fd;
		*start = lst;
	}
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	if (!(lst = (t_struc*)malloc(sizeof(t_struc))))
		return (NULL);
	lst->cont = ft_strdup("");
	lst->next = *start;
	lst->fd = fd;
	*start = lst;
	return (lst);
}

static char	*ft_substr_gnl(char **s, unsigned int start, size_t len, int e)
{
	char *tmp;

	if (e == 1)
	{
		tmp = *s;
		*s = ft_substr(*s, start, len);
		free(tmp);
		return(*s);
	}
	else
	{
		tmp = ft_substr(*s, start, len);
		return (tmp);
	}
}

static char			*ft_strjoin_gnl(char **s1, char *s2, int r)
{
	char	*tmp;

	s2[r] = 0;
	tmp = *s1;
	*s1 = ft_strjoin(*s1, s2);
	free(tmp);
	return (*s1);
}

int				ft_justfree(char *buf, t_struc **start, t_struc *lst, int e)
{
	t_struc		*tmp;

	if ((e == 'a' && lst && lst->cont) || e != 'a')
		free(buf);
	if (lst && e != 'd')
	{
		tmp = *start;
		if (lst == *start)
			*start = lst->next;
		while (tmp->next != lst)
		{
			tmp = tmp->next;
			tmp->next = lst->next;
		}
		if (lst->cont)
			free(lst->cont);
		free(lst);
	}
	if (e == 'a' || e == 'b')
		return (-1);
	if (e == 'c')
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_struc		*start;
	t_struc				*lst;
	char				*buf;
	size_t				r;
	size_t				e;
	int		i;

	i = 0;
	lst = ft_findlst(&start, fd);
	buf = NULL;
	if (!lst || !lst->cont ||
	!(buf = (char*)malloc(sizeof(char) *(BUFFER_SIZE + 1))))
		return (ft_justfree(buf, &start, lst, 'a'));
	while (!(ft_strchr(lst->cont, '\n')) && (r = read(fd, buf, BUFFER_SIZE)) &&
			lst->cont)
	{
		i++;
		lst->cont = ft_strjoin_gnl(&lst->cont, buf, r);
		printf("buf:%i = %s\n", i, lst->cont);
	}
	e = 0;
	while (lst->cont && lst->cont[e] != '\n')
		e++;
	*line = ft_substr_gnl(&lst->cont, 0, e, 0);
	lst->cont = ft_substr_gnl(&lst->cont, e + 1, ft_strlen(lst->cont), 1);
	if (!line || !lst->cont)
		return (ft_justfree(buf, &start, lst, 'b'));
	if (r < BUFFER_SIZE)
		return (ft_justfree(buf, &start, lst, 'c'));
	return (ft_justfree(buf, &start, lst, 'd'));
}
