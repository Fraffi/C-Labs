#include <stdio.h>
#include<math.h>
#include"funcs.h"

int process(FILE *f, int *min)
{
	*min = 0;
	int err = 0, i = 0;
	int j = 0;
	int elem, elem0, elem1;
	
	if (f == NULL)
		err = POINTER_ERR;
	
	printf("Input: ");
	if (err == 0)
	{
		i += 1;
		if (fscanf(f, "%d", &elem1) != 1)
			err = INPUT_ERR;
	}
	if (err == 0)
	{
		i += 1;
		if (fscanf(f, "%d", &elem0) != 1)
			err = INPUT_ERR;
	}
	if (err == 0)
	{
		while (fscanf(f, "%d", &elem) == 1)
		{
			if ((elem1 < elem0) && (elem < elem0))
			{
				if ((j != 0) && ((*min == 0) || (i - 1 - j < *min)))
					*min = i - 1 - j;
				j = i - 1;
			}
			elem1 = elem0;
			elem0 = elem;
			i += 1;
		}
	}
	if (*min == 0)
		err = INPUT_ERR;
	return err;
}


