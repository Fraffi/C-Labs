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

int input_arr_i(long long *min, long long *last)
{
	int err;
	err = 0;
	if (min == last)
		err = 1;
	if (err != 1)
	{
		printf("Введите элементы массива: \n");
		for (long long *tmin = min; tmin != last; tmin++)
		{
			if (scanf("%lld", tmin) != 1)
				err = 1;
		}
	}
	return err;
}

