#include <stdio.h>
#include "myio.h"

int count_digits(long int n);
long int find_pow(int a);

int main()
{
	int i, err, a;
	long int n, power;
	
	printf("Введите натуральное число: ");
	
	err = input_int(&n);
	
	if (err == 0)
	{
		a = count_digits(n);
		printf("Заданное натуральное число = ");
		
		while (a > 0)
		{
			a -= 1;
			power = find_pow(a);
			i = n / power;
			printf("%d", i);
			n %= power;
		}
	}
	else
		printf("Введено неверное значение.");
	
	return err;
}

int count_digits(long int n)
{
	int a;
	a = 0;
	while (n > 0)
	{
		n /= 10;
		a += 1;
	}
	return a;
}

long int find_pow(int a)
{
	long int power;
	power = 1;
	
	for (int k = 0; k < a; k++)
		power *= 10;
	
	return power;
}