#include <stdio.h>
#include"funcs.h"

int process(FILE *f, float *disp)
{
	float avg = 0;
	int err;
	
	fseek(f, 0, SEEK_SET);
	
	err = find_avg(f, &avg);
	if (err == 0)
		*disp = find_disp(f, avg);
	
	return err;
}

int find_avg(FILE *f, float *avg)
{
	int err = 0;
	int n = 0;
	int count = ONLY_LETTERS;
	float x, sum = 0;
	
	while ((err == 0) && (fscanf(f, "%f", &x) == 1))
	{
		if (x > (int)x)
			err = INPUT_ERR;
		count = 1;
		sum += x;
		n += 1;
	}
	if (count == ONLY_LETTERS)
		err = INPUT_ERR;
	
	*avg = sum / n;
	
	return err;
}

float find_disp(FILE *f, float avg)
{
	float disp = 0;
	int x, n = 0;
	float sum = 0;
	
	fseek(f, 0, SEEK_SET);
	
	while (fscanf(f, "%d", &x) == 1)
	{
		sum += (x - avg) * (x - avg);
		n += 1;
	}
	
	disp = sum / n;
		
	return disp;
}


