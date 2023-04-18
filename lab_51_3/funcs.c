#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "funcs.h"

int get_number_by_pos(FILE *file, int pos)
{
	int num;
	
	fseek(file, pos * sizeof(int), SEEK_SET);
	fread(&num, sizeof(int), 1, file);
	
	return num;
}

int put_number_by_pos(FILE *file, int pos, int num)
{
	fseek(file, pos * sizeof(int), SEEK_SET);
	fwrite(&num, sizeof(int), 1, file);
	
	return 0;
}

int file_mode(int argc, char **argv, int *mode)
{
	int err = 0;
	
	if (argc == 3)
	{
		if (strcmp(argv[1], "c") == 0)
			*mode = CREATE;
		if (strcmp(argv[1], "p") == 0)
			*mode = PRINT;
		if (strcmp(argv[1], "s") == 0)
			*mode = SORT;
		if (*mode == 0) 
			err = INPUT_ERR; 
	}
	else
		err = INPUT_ERR;
	
	return err;
}

int create_file(FILE *file)
{
	int err = 0, num;
	unsigned count;
	
	if (file == NULL)
		err = INPUT_ERR;
	
	if (err == 0)
	{
		printf("Input amount of numbers: ");
		if (scanf("%u", &count) != 1)
			err = INPUT_ERR;
		
		srand(time(NULL));
	}
	
	if (err == 0)
		for (int i = 0; i < count; i++)
		{
			num = -100 + rand() % 200;
			fwrite(&num, sizeof(int), 1, file);
		}
		
	return err;
}

int output_file(FILE *file, unsigned count)
{
	int num, err = 0;
	
	if (file == NULL)
		err = INPUT_ERR;
	
	if (err == 0)
	{
		fseek(file, 0, SEEK_SET);
		for (int i = 0; i < count; i++)
		{
			fread(&num, sizeof(int), 1, file);
			printf("%d ", num);
		}
		printf("\n");
	}
	
	return err;
}

int sort_file(FILE *file, unsigned count)
{
	int x;
	int min_i;
	
	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < count - 1; i++)
	{
		min_i = i;
		for (int j = i + 1; j < count; j++) 
		{
			if (get_number_by_pos(file, j) < get_number_by_pos(file, min_i))
			{
				min_i = j;
			}
		}
		x = get_number_by_pos(file, i);
		put_number_by_pos(file, i, get_number_by_pos(file, min_i));
		put_number_by_pos(file, min_i, x);
	}
	
	return 0;
}

int amount_el(FILE *file)
{
	int amount, size;
	
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	amount = size / sizeof(int);
	
	return amount;
}

int check(FILE *file)
{
	int err = 0;
	
	if (file == NULL)
		err = INPUT_ERR;
	if ((err == 0) && (amount_el(file) == 0))
		err = POINTER_ERR;
	
	return err;
}



