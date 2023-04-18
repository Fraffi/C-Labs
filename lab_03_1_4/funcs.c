#include <stdio.h>
#include"funcs.h"

int input_size(int *n)
{
	int err;
	err = 0;
	if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > N))
		err = 1;
	printf("\n");
	return err;
}

int input_arr_i(int *a, int cols)
{
	int err;
	err = 0;
	for (int i = 0; i < cols && !err; i++)
	{
		if (scanf("%d", &a[i]) != 1)
			err = 1;
	}
	return err;
}

int input_matrix(int **matrix, int rows, int cols)
{
	int err = 0;
	
	
	printf("Input elements: \n");
	for (int i = 0; i < rows && !err; i++)
	{
		err = input_arr_i(matrix[i], cols);
	}
	
	return err;
}

int transform(int **matrix, int buffer[][N])
{
	for (int i = 0; i < N; i++)
	{
		matrix[i] = buffer[i];
	}
	return 0;
}

int output_arr(int *a, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}

int output_matrix(int **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		output_arr(matrix[i], cols);
	}
	
	return 0;
}

int arr_assign(int *arr1, int *arr2, int cols, int q)
{
	for (int i = q; i < (cols - q); i++)
	{
		arr1[i] = arr2[i];
	}
	return 0;
}

int process(int **matrix, int rows, int cols)
{
	int arr[N];
	int q, k, err;
	q = 0;
	err = 0;
	k = rows - 1;
	
	if (matrix == NULL)
		err = 1;
	
	for (int i = 0; i < (rows / 2); i++)
	{
		arr_assign(arr, matrix[i], cols, 0);
		arr_assign(matrix[i], matrix[k], cols, q);
		arr_assign(matrix[k], arr, cols, q);
		k -= 1;
		q += 1;
	}
	return err;
}

