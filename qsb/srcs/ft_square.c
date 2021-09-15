#include "ft_square.h"
#include "ft_map.h"
#include <stdbool.h>

bool	isValid(t_square square, t_map map)
{
	int	i;
	int	j;

	i = square.x;
	while (i < map.n - square.size + 1)
	{
		j = square.y;
		while (j < map.m - square.size + 1)
		{
			if (map.tab[i][j] == -1)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
