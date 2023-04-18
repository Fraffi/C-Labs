#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include"funcs.h"

int main(int argc, char **argv)
{
	FILE *file;
	float p = 0, amountf = 0;
	int err = OK, final_amount = 0, amount = 0;
	char string_n[NAME], string_p[NAME];
	char *p_end = NULL;
	
	struct goods arr_struct_g[N];
	
	if (argc != 3)
		err = INPUT_ERR;
	if (err == OK)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
			err = INPUT_ERR;
	}
	if (err == OK)
	{
		err = read_one_num(&p, p_end, errno, argv[2]); // reading price.
		if (err == OK)
			err = read_string(file, string_n);
		if (err == OK)
			err = read_one_num(&amountf, p_end, errno, string_n); // reading amount.
		if (err == OK)
		{
			amount = (int)amountf;
			if ((amount > N) || (amount == 0))
				err = INPUT_ERR;
		}
		if (err == OK)
			err = reading(file, p_end, amount, string_p, string_n, arr_struct_g);
		if (err == OK)
		{
			final_amount = filter(arr_struct_g, p, amount);
			output(arr_struct_g, final_amount);
		}
		fclose(file);
	}
	
	return err;
}