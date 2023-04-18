#include <stdio.h>

long int input_int(long int *n)
{
	int err;
	err = 0;
	if ((scanf("%ld", n) != 1) || (*n <= 0))
	{
		err = 1;
	}
	return err;
}

