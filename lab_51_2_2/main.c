#include<stdio.h>
#include"funcs.h"

int main(int argc, char **argv)
{
	int err = 0;
	int pos;
	float disp = 0;
	FILE *file;
	
	if (argc != 2)
		err = INPUT_ERR;
	if (err == 0)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
			err = POINTER_ERR;
		else
		{
			fseek(file, 0, SEEK_END);
			pos = ftell(file);
			if (pos == 0)
				err = POINTER_ERR;
		}
	}
	if (err == 0)
		err = process(file, &disp);
	
	if (err == 0)
		printf("%f", disp);
	else
		printf("Error.");
	
	return err;
}