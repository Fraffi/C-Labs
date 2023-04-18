#ifndef ADD_H
#define ADD_H

#define POINTER_ERR -1
#define INPUT_ERR -2
#define ONLY_LETTERS -3

int process(FILE *f, float *disp);

int find_avg(FILE *f, float *avg);

float find_disp(FILE *f, float avg);
 
#endif