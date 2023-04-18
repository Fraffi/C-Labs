#include <stdio.h>
#include "funcs.h"

int read(int *n, int *m)
{
	int err = OK;
	
	printf("Input rows: ");
	if (scanf("%d", m) != 1)
		err = INPUT_ERR;
	if (err == OK)
	{
		printf("Input columns: ");
		if (scanf("%d", n) != 1)
			err = INPUT_ERR;
		printf("\n");
	}
	
	return err;
}

int read_elements(int **a, int m, int n)
{
	int err = OK;
	
	printf("Read elements: ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if  (scanf("%d", &a[i][j]) != 1)
				err = INPUT_ERR;
		}
	}
	
	return err;
}

void output(int **a, int m, int n)
{
	printf("\n");
	for (int i = 0; i < m; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
}

void rotate(int **a, int **b, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[j][m - i - 1] = a[i][j];
		}
	}
	//output(b, n, m);
}

void mirroring(int **a, int m, int n)
{
	int tmp;
	
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			tmp = a[i][j];
			a[i][j] = a[m - 1 - j][n - 1 - i];
			a[m - 1 - j][n - 1 - i] = tmp;
		}
	}
}

int is_max(int k, int tmax)
{
	int temp = k;
	int count = 0, tmaxc = 0;
	int flag = 0;
	
	while (temp > 0)
	{
		temp = temp / 10;
		count += 1;
	}
	while (tmax > 0)
	{
		tmax = tmax / 10;
		tmaxc += 1;
	}
	if (count > tmaxc)
		flag = 1;
	if (count == tmaxc)
		flag = -1;
	
	return flag;
}

int is_min(int k, int tmin)
{
	int temp = k;
	int count = 0, tminc = 1;
	int flag = 0;
	
	while (temp > 0)
	{
		temp = temp / 10;
		count += 1;
	}
	while (tmin > 0)
	{
		tmin = tmin / 10;
		tminc += 1;
	}
	if (count < tminc)
		flag = 1;
	if (count == tminc)
		flag = -1;
	
	return flag;
}

int find_string(int **b, int m, int n, int *tmin_str, int *tmax_str)
{
	int tmax = b[0][0], tmin = b[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (is_min(b[i][j], tmin) == 1)
			{
				tmin = b[i][j];
				*tmin_str = i;
			}
			if (is_max(b[i][j], tmax) == 1)
			{
				tmax = b[i][j];
				*tmax_str = i;
			}
		}
	}
	return 0;
}

int refactor(int **b, int m, int n, int tmin_str, int tmax_str)
{
	int tmp;
	int new_rows = n;
	
	if (tmin_str != tmax_str)
	{
		for (int j = 0; j < m; j++)
		{
			tmp = b[tmin_str][j];
			b[tmin_str][j] = b[tmax_str][j];
			b[tmax_str][j] = tmp;
		}
	}
	if (tmin_str == tmax_str)
	{
		for (int i = tmin_str; i < n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				b[i][j] = b[i + 1][j];
			}
		}
		new_rows -= 1;
	}
	
	return new_rows;
}