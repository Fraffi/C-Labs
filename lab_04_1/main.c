#include<stdio.h>
#include<string.h>
#include"funcs.h"

struct test
{
	char origin[M];
	char str[M];
};

int main()
{
	int err = 0;
	int q, k;
	struct test tests[4] = {
		{
		"123456789", "756"
		},
		{
		"qwertyYpO23 44fjgrnfjfnjbjvnjk", "bxcvmbxMbnvnmbm xcNbv44Onmbxbv"
		},
		{
		"ThIs Is ReAlLy Cool STRiNg", "tHiS_iS_tOO"
		},
		{
		"qwe", "rty"
		}
		};
	
	for (int i = 0; i < 4; i++)
	{
		q = my_strcspn(tests[i].origin, tests[i].str);
		k = strcspn(tests[i].origin, tests[i].str);
		if (q == k)
			printf("Test passed.\nMy answer = %d, string.h answer = %d\n", q, k);
		else
		{
			printf("Error\nMy answer = %d, string.h answer = %d\n", q, k);
			err = 1;
		}
	}
	
	return err;
}