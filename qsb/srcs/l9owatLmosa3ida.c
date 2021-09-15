void	set_nm(int **N, int **M, int m, int n)
{
	**N = n;
	**M = m;
}

void	inc(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

void	set_mj(char *buff, int *m, int *j, int i)
{
	while (buff[i + *m] != '\n')
		(*m)++;
	*j = 0;
}

void	set_ijk(int *i, int *j, int *k, int I)
{
	*i = I;
	*k = 0;
	*j = 0;
}

void	inc_and_set(int *i, int *j, int *k)
{
	*j = 0;
	inc(i, k);
}
