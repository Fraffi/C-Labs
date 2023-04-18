#ifndef ADD_H
#define ADD_H

#define M 256
#define WORD 17
#define M_WORDS 129

int transform(char **matrix, char buffer[][WORD]);

int input_string(char *string);

int check_length(char **matrix, char *word, int q, int *repeat_w);

int check_equal_last(char **matrix, int q);

void fill_matrix(int *err, int repeat_w, char **matrix, int *q, int j, char *word);

int parce(char *string, char **matrix, int *q);

int reverse(char **matrix, int q);

int del_letters(char **matrix, int q);

int form_string(char **matrix, int q, char *string);

void output(char **matrix, int q);

void word_copy(char *s1, char *s2);
 
#endif