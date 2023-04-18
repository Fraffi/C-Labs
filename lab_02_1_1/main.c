#include<stdio.h>
#include"myio.h"

int count(int *a, int n);

int main()
{
	int n, err, prod;
	err = input_size(&n);
	int a[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	if (err == 0)
		err = input_arr_i(a, n);
	switch (err)
	{
		case 0:
			prod = count(a, n);
			printf("Произведение нечетных элементов = %d", prod);
			break;
		case 1:
			printf("Введены неверные данные.");
			break;
		case 2:
			printf("Нет нечетных элементов.");
			break;
	}
	return err;
}

int count(int *a, int n)
{
	int prod;
	prod = 1;
	for (int i = 0; i < n; i ++)
	{
		if ((a[i] % 2) != 0)
			prod *= a[i];
	}
	return prod;
}