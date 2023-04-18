#include<stdio.h>
#include"funcs.h"

int main()
{
	int err = 0, q = 0;
	char buffer[M_WORDS][WORD], *matrix[M], string[M];
	transform(matrix, buffer);
	
	printf("Input: ");
	err = input_string(string);
	if (err == 0)
	{
		err = parce(string, matrix, &q);
	}
	if (err == 0)
	{
		sort(matrix, q);
		printf("Result: ");
		output(matrix, q);
	}
	return err;
}