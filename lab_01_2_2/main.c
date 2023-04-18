#include<stdio.h>
#include<math.h>

double find_lenght(double xa, double xb, double ya, double yb);

double perimeter(double l1, double l2, double l3);

int main(void)
{
	double x1, x2, x3, y1, y2, y3, l1, l2, l3, p;
	printf("Введите координаты первой вершины: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Введите координаты второй вершины: ");
	scanf("%lf%lf", &x2, &y2);
	printf("Введите координаты третьей вершины: ");
	scanf("%lf%lf", &x3, &y3);
	
	l1 = find_lenght(x1, x2, y1, y2);
	l2 = find_lenght(x2, x3, y2, y3);
	l3 = find_lenght(x3, x1, y3, y1);
	
	p = perimeter(l1, l2, l3);
	
	printf("Периметр треугольника = %f", p);
	
	return 0;
}

double find_lenght(double xa, double xb, double ya, double yb)
{
	double x, y, side;
	x = xb - xa;
	y = yb - ya;
	side = sqrt(pow(x, 2) + pow(y, 2));
	return side;
}

double perimeter(double l1, double l2, double l3)
{
	double s;
	s = l1 + l2 + l3;
	return s;
}