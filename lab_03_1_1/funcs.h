#ifndef ADD_H
#define ADD_H

#define N 10
#define M 10

int input_size(int *n);
int input_arr_i(int *a, int n);
int transform(int **matrix, int buffer[][N]);
int input_matrix(int **matrix, int m, int n);
int process(int **matrix, int *a, int m, int n);
int is_symm(int *a, int m);
int output_arr(int *a, int n);
 
#endif