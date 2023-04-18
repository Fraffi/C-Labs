#ifndef __funcs_H__
#define __funcs_H__

#define OK 0
#define INPUT_ERR -1

int read(int *n, int *m);

int read_elements(int **a, int m, int n);

void output(int **a, int m, int n);

void rotate(int **a, int **b, int m, int n);

int is_max(int k, int tmax);

int is_min(int k, int tmin);

int find_string(int **b, int m, int n, int *tmin_str, int *tmax_str);

int refactor(int **b, int m, int n, int tmin_str, int tmax_str);

void mirroring(int **a, int m, int n);

#endif