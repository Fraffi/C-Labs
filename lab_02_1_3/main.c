#include<stdio.h>
#include<math.h>
#include"myio.h"

void new_arr(int *a, int n, int counter);

int main()
{
	int n, err, counter;
	
	int a[SIZE];
	
	err = input_size(&n);
	
	if (err == 0)
		err = input_arr_i(a, n, &counter);
	switch (err)
	{
		case 0:
			new_arr(a, n, counter);
			printf("Измененный массив: \n");
			for (int k = 0; k < n + counter; k++)
				printf("%d ", a[k]);
			break;
		case 1:
			printf("Введены неверные данные.");
			break;
	}
	return err;
}

void new_arr(int *a, int n, int counter)
{
	int j, flag;
	int fib1, fib0, fib_temp;
	fib0 = 0;
	fib1 = 1;
	flag = -1;
	for (int i = 0; i < n + counter; i ++)
	{
		if ((a[i] % 3) == 0)
		{
			flag += 1;
			for (j = n + flag; j > i; j--)
				a[j + 1] = a[j];
			a[i + 1] = fib0;
			fib_temp = fib0 + fib1;
			fib0 = fib1;
			fib1 = fib_temp;
			i += 1;
		}
	}
}