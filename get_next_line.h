/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:14:42 by eestela           #+#    #+#             */
/*   Updated: 2020/02/20 18:03:04 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct			s_struc
{
	char				*cont;
	int					fd;
	struct s_struc		*next;
}						t_struc;

int						get_next_line(int fd, char **line);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_substr(char const *s, unsigned int start,
						size_t len);

#endif
