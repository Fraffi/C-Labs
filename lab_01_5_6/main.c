#include<stdio.h>
#include<math.h>
#include"myio.h"

int find_intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4, eps;
	int flag, err;
	
	eps = 1e-7;
	
	printf("Введите координаты начала первого отрезка: \n");
	err = input_double(&x1, &y1);
	if (err == 0)
	{
		printf("Введите координаты конца первого отрезка: \n");
		err = input_double(&x2, &y2);
		if ((fabs(x2 - x1) < eps) && (fabs(y2 - y1) < eps))
			err = 1;
	}
	if (err == 0)
	{
		printf("Введите координаты начала второго отрезка: \n");
		err = input_double(&x3, &y3);
	}
	if (err == 0)
	{
		printf("Введите координаты конца второго отрезка: \n");
		err = input_double(&x4, &y4);
		if ((fabs(x3 - x4) < eps) && (fabs(y3 - y4) < eps))
			err = 1;
	}
	if (err == 0)
	{
		flag = find_intersection(x1, y1, x2, y2, x3, y3, x4, y4);
		if (flag == 0)
		{
			printf("%d \n", flag);
			printf("(не пересекаются)");
		}
		
		if (flag == 1)
		{
			printf("%d \n", flag);
			printf("(пересекаются)");
		}
	}
	if (err != 0)
		printf("Введено неверное значение.");
	return err;
}

int find_intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double a, b, c, a1, b1, c1;
	int intersection;
	
	a = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);
	b = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	c = a * b;
	
	a1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
	b1 = (x4 - x3) * (y2 - y4) - (y4 - y3) * (x2 - x1);
	c1 = a1 * b1;
	
	if ((c < 0) && (c1 < 0))
		intersection = 1;
	else
		intersection = 0;
	
	return intersection;
}
