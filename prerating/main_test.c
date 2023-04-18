#include<stdio.h>
#include"main.h"

int div_mod(int *res, int *m)
{
	int err = 0;
	int a, b;
	scanf("%d %d", &a, &b);
	
	if (b != 0)
	{
		*res = a / b;
		*m = a % b;
	}
	else 
		err = DEVBYZER;
	
	return err;
}

void test1_div_mod()
{
	int a, b;
	int res, m;
	
	a = 12;
	b = 4;
	
	res = a / b;
	m = a % b;


	if ((res == 3) && (m == 0))
		printf("test passed \n");
	else
		printf("test didnt pass \n");
}

void test2_div_mod()
{
	int a, b;
	int res, m;
	
	a = -12;
	b = 4;
	
	res = a / b;
	m = a % b;

	if ((res == -3) && (m == 0))
		printf("test passed \n");
	else
		printf("test didnt pass \n");
}
