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
int sum(int n);
int search(int **matrix, int rows, int cols, int *ei, int *ej);
int process(int **matrix, int rows, int cols, int ei, int ej);
 
#endif