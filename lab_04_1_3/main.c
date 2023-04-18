#include<stdio.h>
#include"funcs.h"

int main()
{
	int err = 0, q = 0;
	char buffer[M_WORDS][WORD], *matrix[M], string[M];
	char new_str[M];
	transform(matrix, buffer);
	
	printf("Input: ");
	err = input_string(string);
	if (err == 0)
	{
		err = parce(string, matrix, &q);
	}
	if (err == 0)
	{
		q = check_equal_last(matrix, q);
		if (q == 0)
			err = 1;
	}
	if (err == 0)
	{
		reverse(matrix, q);
		del_letters(matrix, q);
		form_string(matrix, q, new_str);
		printf("Result: %s\n", new_str);
	}
	return err;
}