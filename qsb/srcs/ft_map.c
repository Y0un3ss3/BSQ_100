#include "ft_map.h"
#include <stdio.h>
#include <stdbool.h>
#include "ft_chars.h"
#include "ft_str.h"
#include "stdlib.h"

void	set_nm(int **N, int **M, int m, int n);
void	inc(int *i, int *j);
void	set_mj(char *buff, int *m, int *j, int i);
void	set_ijk(int *i, int *j, int *k, int I);
void	inc_and_set(int *i, int *j, int *k);

bool	is_printable(char c)
{
	return (c >= ' ' && c != 127);
}

int getFirstNewLine(char *buff) {
	int i;
	i = 0;

	while(buff[i]) {
		if(buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	checkFirstLine(char *buff, int *numberOflines, t_chars *chars)
{
	int	i;
	int N = getFirstNewLine(buff);

	if (buff[0] == '\0' || N == -1)
		return (-1);
	if (!(buff[0] >= '0' && buff[0] <= '9'))
		return (-1);
	i = 0;
	*numberOflines = 0;
	while (buff[i] >= '0' && buff[i] <= '9' && i < N - 3)
	{
		*numberOflines = (*numberOflines * 10) + (buff[i] - '0');
		i++;
	}
	if (!is_printable(buff[i]) || !is_printable(buff[i + 1])
		|| !is_printable(buff[i + 2]) || buff[i + 3] != '\n')
		return (-1);
	if (buff[i] == buff[i + 1] || buff[i] == buff[i + 2]
		|| buff[i + 1] == buff[i + 2])
		return (-1);
	chars->empty = buff[i];
	chars->obstacle = buff[i + 1];
	chars->full = buff[i + 2];
	return (i + 4);
}

bool	checkNewline(int *j, int *m, int *numberOflines, int *i)
{
	if (*j != *m)
		return (0);
	*j = 0;
	(*numberOflines)--;
	(*i)++;
	return (true);
}

bool	validMap(char *buff, t_chars *chars, int *N, int *M)
{
	int		i;
	int		m;
	int		j;
	int		numberOflines;
	int     flag;

	i = checkFirstLine(buff, &numberOflines, chars);
	if (i == -1)
		return (false);
	m = 0;
	set_mj(buff, &m, &j, i);
	set_nm(&N, &M, m, numberOflines);
	flag = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			if (checkNewline(&j, &m, &numberOflines, &i) == false)
				return (false);
			continue ;
		}
		flag = 1;
		if (buff[i] != chars->empty && buff[i] != chars->obstacle)
			return (false);
		inc(&i, &j);
	}
	return (numberOflines == 0 && flag);
}

t_map	iget_map(char *buff)
{
	t_map	ans;
	int		i;
	int		k;
	int		j;

	ans.tab = NULL;
	if (validMap(buff, &ans.chars, &ans.n, &ans.m) == false)
		return (ans);
	ans.tab = (int **)malloc(sizeof(int *) * ans.n);
	i = 0;
	while (i < ans.n)
		ans.tab[i++] = (int *)malloc(sizeof(int) * ans.m);
	set_ijk(&i, &j, &k, checkFirstLine(buff, &ans.n, &ans.chars));
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			inc_and_set(&i, &j, &k);
			continue ;
		}
		ans.tab[k][j] = (buff[i] == ans.chars.empty);
		inc(&i, &j);
	}
	return (ans);
}
