#ifndef ADD_H
#define ADD_H

#define OK 0
#define INPUT_ERR -1

#define N 15
#define NAME 26

struct goods 
{
	char name[NAME + 1];
	int price;
};

int reading(FILE *file, char *p_end, int amount, char *string_p, char *string_n, struct goods *arr_struct_g);

int read_one_num(float *num, char *p_end, int errn, char *string);

int put_into_struct(char *string, int price, struct goods *arr_struct);

int read_string(FILE *file, char *string);

void output(struct goods *arr_struct, int amount);

int check_num(char *p_end, int errn);

int filter(struct goods *arr_struct, float p, int amount);
 
#endif