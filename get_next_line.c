/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:17:32 by eestela           #+#    #+#             */
/*   Updated: 2019/11/24 19:11:56 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_struc		*ft_findfill(t_struc *start, int fd)
{
	t_struc		*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = malloc(sizeof(t_struc))))
		return (NULL);
	tmp->fd = fd;
	tmp->next = start;
	if (!(tmp->content = malloc(sizeof(char))))
		return (NULL);
	tmp->content = 0;
	start = tmp;
	return (tmp);
}

static char	*ft_strjoingnl(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*new;
	int		j;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free ((void*)s1);
	return (new);
}


static void			*ft_toreturn(char **line, t_struc *lst)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (lst->content[j] != '\n' && lst->content)
		*line[i++] = lst->content[j++];
	line[i] = 0;
	j = 0;
	while (lst->content[i])
		lst->content[j++] = lst->content[i++];
	lst->content[j] = 0;
}

int					get_next_line(int fd, char **line)
{
	static t_struc	*start;
	t_struc			*lst;
	char			*buf;
	int				r;

	lst = ft_findfill(start, fd);
	if(!(buf = malloc (sizeof(char) * (BUFFER_SIZE + 1)))
		return (-1);
	while (r = read(fd, buf, BUFFER_SIZE))
	{
		buf[r] = '\0';
		lst->content = ft_strjoingnl(lst->content, buf);
		if (ft_strchr(lst->content, '\n'))
			break ;
	}
	ft_toreturn(line, lst);
}
