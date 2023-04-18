#include <stdio.h>

int input_double(double *x, double *y)
{
	int err;
	err = 0;
	if (scanf("%lf%lf", x, y) != 2)
	{
		err = 1;
	}
	return err;
}


