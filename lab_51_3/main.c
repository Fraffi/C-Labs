/*
Тип - int
Сортировка - выбором
Направление упорядочивания - возрастание.
*/

#include <stdio.h>
#include "funcs.h"

int main(int argc, char **argv)
{
	int err, mode = 0;
	unsigned count;
	FILE *file;
	
	err = file_mode(argc, argv, &mode);
	
	if (err == 0)
	{
		if (mode == CREATE)
		{
			file = fopen(argv[2], "wb");
			err = create_file(file);
			if (err == 0)
				fclose(file);
		}
		if (mode == SORT)
		{
			file = fopen(argv[2], "rb+");
			err = check(file);
			if (err == 0)
			{
				count = amount_el(file);
				sort_file(file, count);
				fclose(file);
			}
		}
		if (mode == PRINT)
		{
			file = fopen(argv[2], "rb");
			err = check(file);
			if (err == 0)
			{
				count = amount_el(file);
				output_file(file, count);
				fclose(file);
			}
		}
		//fseek(file, 0, SEEK_SET);
	}
	if (err != 0)
		printf("Error.");
	
	return err;
}