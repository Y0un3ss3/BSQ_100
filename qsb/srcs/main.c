/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mans <yel-mans@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:31:00 by iel-moun          #+#    #+#             */
/*   Updated: 2021/08/24 02:07:00 by yel-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_map.h"
#include "ft_square.h"
#include <stdio.h>
#include "ft_str.h"
#include "ft_algo.h"
#include <stdlib.h>
void	stdin_solveMap(void);

char	*buffer_duplicate(char *buffer)
{
	char	*bt;
	int		i;

	bt = (char *) malloc(sizeof(char) * (2 + ft_strlen(buffer)));
	i = 0;
	while (buffer[i])
	{
		bt[i] = buffer[i];
		i++;
	}
	bt[i] = '\0';
	return (bt);
}

void	buffer_pusher(char **buffer, char c)
{
	char	*bt;
	int		i;

	if (*buffer == 0)
	{
		*buffer = (char *)malloc(sizeof(char) * 2);
		**buffer = c;
		*(*buffer + 1) = 0;
	}
	else
	{
		bt = buffer_duplicate(*buffer);
		i = ft_strlen(bt);
		bt[i] = c;
		bt[i + 1] = 0;
		free(*buffer);
		*buffer = bt;
	}
}

void	printGrid(t_map mp)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp.n)
	{
		j = 0;
		while (j < mp.m)
		{
			if (mp.tab[i][j] == 1)
				write(1, &mp.chars.empty, 1);
			else if (mp.tab[i][j] == 0)
				write(1, &mp.chars.obstacle, 1);
			else
				write(1, &mp.chars.full, 1);
			j++;
		}
		i++;
		ft_putstr("\n", 1);
	}
}

void	solveMap(char *path)
{
	char	c;
	char	*buff;
	t_map	mp;
	int		fd;

	buff = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	if (read(fd, 0, 0) == -1)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	while (read(fd, &c, 1) > 0)
		buffer_pusher(&buff, c);
	close(fd);

	if (buff == 0)
	{
		ft_putstr("map error\n", 2);
		return;
	}

	mp = iget_map(buff);
	free(buff);
	if (mp.tab == NULL)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	getMaxSubSquare(mp.tab, mp.n, mp.m);
	printGrid(mp);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		stdin_solveMap();
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			solveMap(argv[i]);
			i++;
		}
	}
	return (0);
}
