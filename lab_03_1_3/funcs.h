#ifndef ADD_H
#define ADD_H

#define N 10
#define M 10

int input_size(int *n);
int input_arr_i(int *a, int cols);
int input_matrix(int **matrix, int rows, int cols);
int transform(int **matrix, int buffer[][N]);
int output_arr(int *a, int cols);
int output_matrix(int **matrix, int rows, int cols);
//int count_max(int **matrix, int rows, int cols, int i);
int count_max(int *arr, int cols);
int arr_assign(int *arr1, int *arr2, int cols);
int process(int **matrix, int rows, int cols);
 
#endif