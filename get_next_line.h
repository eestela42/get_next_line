/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:11:41 by eestela           #+#    #+#             */
/*   Updated: 2019/11/24 18:20:14 by eestela          ###   ########.fr       */
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
	char				*content;
	int					fd;
	struct s_struc		*next;
}						t_struc;
size_t					ft_strlen(const char *s);
int						get_next_line(int fd, char **line);
char					*ft_strchr(const char *s, int c);
#endif
