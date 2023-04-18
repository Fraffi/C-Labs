#include<stdio.h>
#include<math.h>
#include"myio.h"

#define MAXS 10

long long count(long long *min, long long *last);

int main()
{
	int n, err;
	long long sum;
	
	long long a[MAXS];
	
	err = input_size(&n);
	
	long long *min = a;
	long long *last = min + n;
	
	if (err == 0)
		err = input_arr_i(min, last);
	
	switch (err)
	{
		case 0:
			sum = count(min, last);
			printf("Значение: %lld", sum);
			break;
		case 1:
			printf("Введены неверные данные.");
			break;
	}
	return err;
}

long long count(long long *min, long long *last)
{
	long long sum, d;
	long long *pa = min;
	int flag;

	d = 1;
	sum = 0;
	flag = 0;
	
	while ((!flag) && (pa != last))
	{
		d *= *pa;
		sum += d;
		if (*pa < 0)
			flag = 1;
		pa += 1;
	}
	return sum;	
}