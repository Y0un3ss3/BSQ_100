#include "ft_map.h"
#include "ft_algo.h"
#include <stdlib.h>
#include "ft_str.h"
#include <unistd.h>

void	buffer_pusher(char **buffer, char c);
void	printGrid(t_map mp);

void	stdin_solveMap(void)
{
	char	c;
	char	*buff;
	t_map	mp;

	buff = 0;
	while (read(0, &c, 1))
		buffer_pusher(&buff, c);
	mp = iget_map(buff);
	free(buff);
	if (mp.tab == 0)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	getMaxSubSquare(mp.tab, mp.n, mp.m);
	printGrid(mp);
}
