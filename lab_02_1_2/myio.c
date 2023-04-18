#include <stdio.h>
#include<math.h>

int input_size(int *n)
{
	int err;
	err = 0;
	printf("Введите количество элементов массива: ");
	if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > 10))
		err = 1;
	printf("\n");
	return err;
}

int input_arr_i(int *a, int n)
{
	int err, counter;
	err = 0;
	counter = 0;
	printf("Введите элементы массива: \n");
	for (int i = 0; i < n && !err; i++)
	{
		if (scanf("%d", &a[i]) != 1)
			err = 1;
		if ((err == 0) && (a[i] == 2))
			counter = 1;
		if ((err == 0) && (a[i] > 2) && (counter == 0) && (a[i] != 4))
		{
			counter = 1;
			for (int d = 2; d < sqrt(a[i]); d++)
				if ((a[i] % d) == 0)
					counter = 0;
		}
	}
	if ((counter == 0) && (err != 1))
		err = 2;
	return err;
}

