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

int input_arr_i(int *a, int n)
{
	int err;
	err = 0;
	for (int i = 0; i < n; i++)
	{
		if (scanf("%d", &a[i]) != 1)
			err = 1;
	}
	return err;
}

int input_matrix(int **matrix, int n, int m)
{
	int err = 0;
	
	if (err == 0)
	{
		printf("Input elements: \n");
		for (int i = 0; i < m; i++)
		{
			err = input_arr_i(matrix[i], n);
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

int output_arr(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}

/*int output_matrix(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        out_array(matrix[i], n);
    }
    
    return 0;
}*/

int is_symm(int *a, int n)
{
	int flag = 0;
	int *start = a, *end = a + n - 1;
	while (start <= end)
	{
		if (*start != *end)
		{
			flag = 1;
		}
		start += 1;
		end -= 1;
	}
	return flag;
}

int process(int **matrix, int *a, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (is_symm(matrix[i], n) == 0)
		{
			a[i] = 1;
		}
	}
	return 0;
}


