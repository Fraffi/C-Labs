#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include"funcs.h"

int put_into_struct(char *string, int price, struct goods *arr_struct)
{
	strcpy(arr_struct->name, string);
	arr_struct->price = price;
	
	return 0;
}

int read_string(FILE *file, char *string)
{
	int err = OK;
	int length = 0;
	if (fgets(string, NAME + 2, file) == NULL)
		err = INPUT_ERR;
	if (err == OK)
	{
		length = strlen(string);
		if (string[length - 1] == '\n')
		{
			string[length - 1] = '\0';
			length -= 1;
		}
		if ((length > 0) && (string[length - 1] == '\r'))
		{
			string[length - 1] = '\0';
			length -= 1;
		}
	}
	if ((length > NAME) || (length == 0))
		err = INPUT_ERR;
	return err;
}

void output(struct goods *arr_struct, int amount)
{
	for (int k = 0; k < amount; k++)	
		printf("%s\n%d\n", arr_struct[k].name, arr_struct[k].price);
}

int check_num(char *p_end, int errn)
{
	int err = OK;
	
	if (errn == EINVAL)
		err = INPUT_ERR;
	if (errn == ERANGE)
		err = INPUT_ERR;
	if (*p_end != '\0')
		err = INPUT_ERR;
	
	return err;
}

int filter(struct goods *arr_struct, float p, int amount)
{
	int i = 0, k = 0;
	int temp_amount = amount;
	
	while (k < temp_amount)
	{
		if (arr_struct[k].price >= p)
		{	
			for (i = k; i < (temp_amount - 1); i++)
			{
				arr_struct[i].price = arr_struct[i + 1].price;
				strcpy(arr_struct[i].name, arr_struct[i + 1].name);
			}
			temp_amount -= 1;
		}
		else
			k += 1;
	}
	
	return temp_amount;
}

int reading(FILE *file, char *p_end, int amount, char *string_p, char *string_n, struct goods *arr_struct_g)
{
	int err = OK;
	long int price = 0;
	
	int i = 0;
	while ((err == OK) && (i < amount))
	{
		err = read_string(file, string_n);
		if (err == OK)
			err = read_string(file, string_p);
		if (err == OK)
		{
			price = strtol(string_p, &p_end, 10);
			if (price <= 0)
				err = INPUT_ERR;
		}
		if (err == OK)
			err = check_num(p_end, errno);
		if (err == OK)
		{
			put_into_struct(string_n, price, &arr_struct_g[i]);
			i += 1;
		}
	}
	if (read_string(file, string_n) == OK)
		err = INPUT_ERR;
		
	return err;
}

int read_one_num(float *num, char *p_end, int errn, char *string)
{
	int err = OK;
	
	*num = strtof(string, &p_end);
	if (*num < 0)
		err = INPUT_ERR;
	if (err == OK)
		err = check_num(p_end, errn);
	
	return err;
}