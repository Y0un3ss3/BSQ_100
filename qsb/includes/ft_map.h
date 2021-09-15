#ifndef FT_MAP_H
# define FT_MAP_H
# include "ft_chars.h"
typedef struct s_map
{
	int		**tab;
	int		n;
	int		m;
	t_chars	chars;
}	t_map;
t_map	iget_map(char *buff);
#endif