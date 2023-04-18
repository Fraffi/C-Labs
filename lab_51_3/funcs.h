#ifndef ADD_H
#define ADD_H

#define POINTER_ERR -1
#define INPUT_ERR -2

#define CREATE 1
#define PRINT 2
#define SORT 3

int get_number_by_pos(FILE *file, int pos);

int put_number_by_pos(FILE *file, int pos, int num);

int file_mode(int argc, char **argv, int *mode);

int create_file(FILE *file);

int output_file(FILE *file, unsigned count);

int sort_file(FILE *file, unsigned count);

int amount_el(FILE *file);

int check(FILE *file);
 
#endif