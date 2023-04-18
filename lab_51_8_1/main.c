#include<stdio.h>
#include"funcs.h"

int main()
{
	int err, min;
	
	err = process(stdin, &min);
	
	if (err == 0)
		printf("%d", min);
	else
		printf("Error.");
	return err;
}