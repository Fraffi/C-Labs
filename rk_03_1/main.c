#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main()
{
	// Переписываю, отзеркалить матрицу вокруг диагонали => матрица квадратная.
	int err = OK;
	int m, n;
	int **a;
	int **b;
	//int new_rows;
	
	err = read(&n, &m);
	
	a = malloc(sizeof(int*)*m);
	for (int i = 0; i < m; i++)
		a[i] = malloc(sizeof(int)*n);
	b = malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		b[i] = malloc(sizeof(int)*m);
	
	err = read_elements(a, m, n);
	output(a, m, n);
	//rotate(a, b, m, n);
	
	//int tmin_str = 0, tmax_str = 0;
	//find_string(b, m, n, &tmin_str, &tmax_str);
	//printf("\nstrings: %d, %d", tmin_str, tmax_str);
	
	//new_rows = refactor(b, m, n, tmin_str, tmax_str);
	//output(b, new_rows, m);
	
	mirroring(a, m, n);
	output(a, m, n);
	
	for (int i = 0; i < m; i++)
		free(a[i]);
	free(a);
	for (int i = 0; i < n; i++)
		free(b[i]);
	free(b);
	
	return err;
}