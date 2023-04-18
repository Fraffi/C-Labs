#include<stdio.h>
#include"myio.h"
#include<math.h>

double row_count(double eps, double x);

int main()
{
	double eps, x, sum, func, rel_err, abs_err;
	int err;
	
	printf("Введите x: ");
	err = input_double(&x, 0);
	if (err == 0)
	{
		printf("Введите точность eps: ");
		err = input_double(&eps, 1);
	}
	if (err == 0)
	{
		sum = row_count(eps, x);
		
		func = 1 / sqrt(1 - x * x);
		
		abs_err = fabs(func - sum);
		
		rel_err = fabs(1 - sum / func);
		
		printf("Точное значение функции = %lf \n", func);
		printf("Значение функции с точностью eps = %lf \n", sum);
		printf("Абсолютная погрешность = %lf \n", abs_err);
		printf("Относительная погрешность = %lf \n", rel_err);
	}
	else
		printf("Введено неправильное значение.");
	return err;
}

double row_count(double eps, double x)
{
	double sum, d, n;
	
	d = 1;
	n = 2;
	sum = 1;
	
	while (fabs(d) > eps)
	{
		d *= ((n - 1) * x * x) / n;
		sum += d;
		n += 2;
	}
	
	return sum;
}