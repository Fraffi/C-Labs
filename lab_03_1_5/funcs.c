#include <stdio.h>
#include <stdlib.h>
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

int input_arr_i(int *a, int cols, int *count)
{
	int err;
	err = 0;
	
	for (int i = 0; i < cols && !err; i++)
	{
		if (scanf("%d", &a[i]) != 1)
			err = 1;
		if ((*count == 0) && (err == 0) && (sum(a[i]) > 10))
			*count = 1;
	}
	return err;
}

int input_matrix(int **matrix, int rows, int cols)
{
	int err = 0;
	int count = 0;
	
	
	printf("Input elements: \n");
	for (int i = 0; i < rows && !err; i++)
	{
		err = input_arr_i(matrix[i], cols, &count);
	}
	if (count == 0)
		err = 1;
	
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

int arr_assign(int *arr1, int *arr2, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		arr1[i] = arr2[i];
	}
	return 0;
}

int sum(int n)
{
	int sum = 0;
	n = abs(n);
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int form_arr(int *arr, int **matrix, int rows, int cols)
{
	int q = 0;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (sum(matrix[i][j]) > 10)
			{
				arr[q] = matrix[i][j];
				q += 1;
			}
		}
	}
	return q;
}

int move_arr(int *arr, int q)
{
	int x;
	for (int i = 0; i < 3; i++)
	{
		x = arr[0];
		for (int j = 0; j < q - 1; j++)
			arr[j] = arr[j + 1];
		arr[q - 1] = x;
	}
	return 0;
}

int process(int **matrix, int *arr, int rows, int cols)
{
	int q = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (sum(matrix[i][j]) > 10)
			{
				matrix[i][j] = arr[q];
				q += 1;
			}
		}
	}
	return 0;
}

