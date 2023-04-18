#include <stdio.h>

int input_double(double *x, int mode)
{
	int err, a;
	err = 0;
	
	if (mode == 0)
		a = -1;
	else
		a = 0;
	if ((scanf("%lf", x) != 1) || ((*x >= 1) || (*x <= a)))
	{
		err = 1;
	}
	return err;
}


