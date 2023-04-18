#include<stdio.h>
#include<math.h>
#include"myio.h"

void sort(int *a, int n);
void swap(int *a, int *b);

int main()
{
	int n, err;
	int a[SIZE];
	
	err = input_size(&n);
	
	if (err == 0)
		err = input_arr_i(a, n);
	switch (err)
	{
		case 0:
			sort(a, n);
			printf("Измененный массив: \n");
			for (int k = 0; k < n; k++)
				printf("%d ", a[k]);
			break;
		case 1:
			printf("Введены неверные данные.");
			break;
	}
	return err;
}

void sort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		int min_i = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (a[j] < a[min_i]) 
			{
				min_i = j;
			}
		}
		swap(a + i, a + min_i);
	}
}

void swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}