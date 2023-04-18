#include<stdio.h>
#include<math.h>

double resistance(double r1, double r2, double r3);

int main(void)
{
	double r1, r2, r3, r;
	printf("Введите три сопротивления: ");
	scanf("%lf%lf%lf", &r1, &r2, &r3);
	r = resistance(r1, r2, r3);
	printf("Сопротивление соединения = %lf", r);
	return 0;
}

double resistance(double r1, double r2, double r3)
{
	double r;
	r = 1 / (1 / r1 + 1 / r2 + 1 / r3);
	return r;
}