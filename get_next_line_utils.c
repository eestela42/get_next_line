/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:54:27 by eestela           #+#    #+#             */
/*   Updated: 2019/11/24 18:18:24 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char *pointer;

	pointer = (char *)s;
	while (*pointer != '\0')
	{
		if (*pointer == c)
			return (pointer);
		pointer++;
	}
	if (c == '\0')
		return (pointer);
	return (NULL);
}
