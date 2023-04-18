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
	for (int i = 0; i < cols; i++)
	{
		if (scanf("%d", &a[i]) != 1)
			err = 1;
	}
	return err;
}

int input_matrix(int **matrix, int rows, int cols)
{
	int err = 0;
	
	if (err == 0)
	{
		printf("Input elements: \n");
		for (int i = 0; i < rows; i++)
		{
			err = input_arr_i(matrix[i], cols);
		}
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

int count_max(int *arr, int cols)
{
	int max = arr[0];
	for (int j = 0; j < cols; j++)
	{
		if (arr[j] > max)
			max = arr[j];
	}
	return max;
}

int arr_assign(int *arr1, int *arr2, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		arr1[i] = arr2[i];
	}
	return 0;
}

int process(int **matrix, int rows, int cols)
{
	int arr[N];
	int max, x, max_i;
	
	max = count_max(matrix[0], cols);
	for (int i = 0; i < rows - 1; i++)
	{
		max_i = i;
		for (int j = i + 1; j < rows; j++) 
		{
			x = count_max(matrix[j], cols);
			max = count_max(matrix[max_i], cols);
			if (x > max) 
			{
				max_i = j;
				max = x;
			}
		}
		arr_assign(arr, matrix[i], cols);
		arr_assign(matrix[i], matrix[max_i], cols);
		arr_assign(matrix[max_i], arr, cols);
	}
	return 0;
}


