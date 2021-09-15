#include <stdlib.h>
#include "ft_str.h"
#include <stdio.h>

int	min(int a, int b, int c)
{
	int	m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	set_s(int ***S, int R, int C, int **M)
{
	int	i;
	int	j;

	*S = malloc(sizeof(int *) * R);
	i = 0;
	while (i < R)
		(*S)[i++] = malloc(sizeof(int) * C);
	i = 0;
	while (i < R)
	{
		(*S)[i][0] = M[i][0];
		i++;
	}
	j = 0;
	while (j < C)
	{
		(*S)[0][j] = M[0][j];
		j++;
	}
}

void	build_s(int ***S, int R, int C, int **M)
{
	int	i;
	int	j;

	j = 0;
	while (j < C)
	{
		(*S)[0][j] = M[0][j];
		j++;
	}
	i = 1;
	while (i < R)
	{
		j = 1;
		while (j < C)
		{
			if (M[i][j] == 1)
				(*S)[i][j] = min((*S)[i][j - 1], (*S)[i - 1][j],
						(*S)[i - 1][j - 1]) + 1;
			else
				(*S)[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	build_max(int *max, int **S, int R, int C)
{
	int	i;
	int	j;

	max[0] = S[0][0];
	max[1] = 0;
	max[2] = 0;
	i = 0;
	while (i < R)
	{
		j = 0;
		while (j < C)
		{
			if (max[0] < S[i][j])
			{
				max[0] = S[i][j];
				max[1] = i;
				max[2] = j;
			}
			j++;
		}
		i++;
	}
}

void	getMaxSubSquare(int **M, int R, int C)
{
	int		i;
	int		j;
	int		**S;
	int		max[3];

	set_s(&S, R, C, M);
	build_s(&S, R, C, M);
	build_max(max, S, R, C);
	i = max[1];
	while (i > max[1] - max[0])
	{
		j = max[2];
		while (j > max[2] - max[0])
		{
			if (i >= 0 && i < R && j >= 0 && j < C)
				M[i][j] = 2;
			j--;
		}
		i--;
	}
}
