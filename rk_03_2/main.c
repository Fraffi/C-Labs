#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INPUT_ERR -1

int rotate(int **arr, int st, int col, int **new_arr);

//Работает только наквадратных, я не успел((

int main()
{
	int err = OK;
	int st, col;
	int **arr;
	int **new_arr;
	
	scanf("%d", &st);
	scanf("%d", &col);
	
	arr = malloc(st * sizeof(int *));
	new_arr = malloc(col * sizeof(int *));
	for (int i = 0; i < col; i++)
		arr[i] = malloc(col * sizeof(int));
	for (int i = 0; i < st; i++)
		new_arr[i] = malloc(st * sizeof(int));
	
	for (int i = 0; i < st; i++)
		for (int j = 0; j < col; j++)
			if (scanf("%d", &arr[i][j]) != 1)
				err = INPUT_ERR;
	
	for (int i = 0; i < st; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	
	
	rotate(arr, st, col, new_arr);
	
	
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < st; j++)
			printf("%d ", new_arr[i][j]);
		printf("\n");
	}
	
	for (int i = 0; i < col; i++)
		free(arr[i]);
	free(arr);
	for (int i = 0; i < st; i++)
		free(new_arr[i]);
	free(new_arr);
	
	return err;
}

int rotate(int **arr, int st, int col, int **new_arr)
{
	int k = -1, l = -1;
	for (int j = col - 1; j >= 0; j--)
	{
		k += 1;
		l = -1;
		for (int i = 0; i < st; i++)
		{
			l += 1;
			new_arr[k][l] = arr[i][j];
		}
	}
	return 0;
}