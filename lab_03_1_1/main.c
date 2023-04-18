#include<stdio.h>
#include"funcs.h"

int main()
{
	int n, m, err;
	int buffer[M][N], *matrix[M];
	int arr[N] = { 0 };
	
	
	printf("Input columns: \n");
	err = input_size(&m);
	if (err == 0)
	{
		printf("Input rows: \n");
		err = input_size(&n);
	}
	
	if (err == 0)
		transform(matrix, buffer);
	if (err == 0)
		err = input_matrix(matrix, n, m);
	if (err == 0)
	{
		process(matrix, arr, n, m);
		printf("\n");
		output_arr(arr, m);
	}
	if (err != 0)
		printf("Error.\n");
	
	return err;
}