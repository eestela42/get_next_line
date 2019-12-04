/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:28:07 by eestela           #+#    #+#             */
/*   Updated: 2019/12/04 15:35:58 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;
	int		x;
	int		y;
	int		z;
	int		fd0;
	int		fd1;
	int		fd2;
	char	*line;
	int l;
	l = 1;
	x = 1;
	y = 1;
	z = 1;
	fd0 = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	fd2 = open(av[3], O_RDONLY);
	while (x > 0 || y > 0 || z > 0)
	{
		printf ("\nligne: %i\n", l);
		if (x > 0)
		{
			x = get_next_line(fd0, &line);
			printf("text1: %s\n", line);
			free(line);
		}/*
		if (y > 0)
		{
			y = get_next_line(fd1, &line);
			printf("text2: %s\n", line);
			free(line);
		}
		if (z > 0)
		{
			z = get_next_line(fd2, &line);
			printf("text3: %s\n", line);
			free(line);
		}*/
		l++;
	}
	//while (1);
	return (0);
}
/*
   int		main(int ac, char **av)
   {
   int		i;
   int		x;
   int		fd0;
   int		fd1;
   int		fd2;
   char	*line;
   if (ac > 1)
   {
   x = 0;
   fd0 = open(av[1], O_RDONLY);
   fd1 = open(av[2], O_RDONLY);
   fd2 = open(av[3], O_RDONLY);
   while ((x < 4) && ((i = get_next_line(fd0, &line)) > 0))
   {
   printf("%d :%s\n", i, line);
   free(line);
   x++;
   }		while ((i = get_next_line(fd1, &line)) > 0)
   {
   printf("%d :%s\n", i, line);
   free(line);
   }
   printf("%d :%s\n", i, line);
   free(line);
   x = 0;
   while ((x < 1) && ((i = get_next_line(fd0, &line)) > 0))
   {
   printf("%d :%s\n", i, line);
   free(line);
   x++;
   }
   while ((i = get_next_line(fd2, &line)) > 0)
   {
   printf("%d :%s\n", i, line);
   free(line);
   }
   printf("%d :%s\n", i, line);
   free(line);
   while ((i = get_next_line(fd0, &line)) > 0)
   {
   printf("%d :%s\n", i, line);
   free(line);
   }
   printf("%d :%s\n", i, line);
   free(line);
   }
   return (0);
   }
   */
