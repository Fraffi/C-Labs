#include<stdio.h>

void format_time(unsigned long t, unsigned long *h, unsigned long *m, unsigned long *s);

int main()
{
	unsigned long t, h, m, s;
	printf("Введите время в секундах: ");
	scanf("%lu", &t);
	
	format_time(t, &h, &m, &s);
	
	printf("Время в формате Ч:М:С = ");
	printf("%lu %lu %lu", h, m, s);
	return 0;
}

void format_time(unsigned long t, unsigned long *h, unsigned long *m, unsigned long *s)
{
	*h = t / 3600;
	*m = t / 60 % 60;
	*s = t % 60;
}