#include<stdio.h>
#include"main.h"

int main(void)
{
	int err = 0;
	int res;
	int m;
	
	err = div_mod(&res, &m);
	
	if(!err)
		printf("%d %d", res, m);
	else
		printf("Error");
	
	test1_div_mod();
	test2_div_mod();
	
	return err;
}