#include<stdio.h>
#include<math.h>
#include"myio.h"

#define PRIME 0
#define NOT_PRIME 1

int new_arr(int *a, int *b, int n);
int prime_inf(int *a, int i);

int main()
{
	int n, err, b_size;
	
	int a[SIZE];
	
	int b[SIZE];
	
	err = input_size(&n);
	
	if (err == 0)
		err = input_arr_i(a, n);
	switch (err)
	{
		case 0:
			b_size = new_arr(a, b, n);
			printf("Массив созданный из простых чисел из массива а: \n");
			for (int k = 0; k < b_size; k++)
				printf("%d ", b[k]);
			break;
		case 1:
			printf("Введены неверные данные.");
			break;
		case 2:
			printf("Нет простых чисел.");
			break;
	}
	return err;
}

int new_arr(int *a, int *b, int n)
{
	int j, is_prime;
	j = 0;
	for (int i = 0; i < n; i ++)
	{
		if (a[i] == 2)
		{
			b[j] = a[i];
			j += 1;
		}
		if ((a[i] > 2) && (a[i] != 4))
		{
			is_prime = prime_inf(a, i);
			if (is_prime == PRIME)
			{
				b[j] = a[i];
				j += 1;
			}
		}
	}
	return j;
}

int prime_inf(int *a, int i)
{
	int d;
	int is_prime;
	
	is_prime = PRIME;
	for (d = 2; d < sqrt(a[i]); d++)
	{
		if ((a[i] % d) == 0)
		{
			is_prime = NOT_PRIME;
		}
	}
	return is_prime;
}