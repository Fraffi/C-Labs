#include<stdio.h>
#include"funcs.h"

int main()
{
	int rows, cols, err;
	int buffer[M][N], *matrix[M];
	
	printf("Input rows: \n");
	err = input_size(&rows);
	if (err == 0)
	{
		printf("Input columns: \n");
		err = input_size(&cols);
	}
	
	if (err == 0)
		transform(matrix, buffer);
	if (err == 0)
		err = input_matrix(matrix, rows, cols);
	if (err == 0)
	{
		process(matrix, rows, cols);
		printf("\n");
		output_matrix(matrix, rows, cols);
	}
	if (err != 0)
	{
		printf("Error.\n");
	}
	
	return err;
}