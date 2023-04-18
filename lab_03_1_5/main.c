#include<stdio.h>
#include"funcs.h"

int main()
{
	int rows, cols, err;
	int buffer[M][N], *matrix[M];
	int q, arr[N];
	transform(matrix, buffer);
	
	printf("Input rows: \n");
	err = input_size(&rows);
	if (err == 0)
	{
		printf("Input columns: \n");
		err = input_size(&cols);
	}
	if (err == 0)
		err = input_matrix(matrix, rows, cols);
	if (err == 0)
		q = form_arr(arr, matrix, rows, cols);
	//if (q == 0)
	//	err = 1;
	if (err == 0)
	{
		move_arr(arr, q);
		process(matrix, arr, rows, cols);
		printf("\n");
		output_matrix(matrix, rows, cols);
	}
	
	return err;
}