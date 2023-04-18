#ifndef ADD_H
#define ADD_H

#define M 256
#define WORD 16
#define M_WORDS 129

int transform(char **matrix, char buffer[][WORD]);

int input_string(char *string);

int check(char **matrix, char *word, int q, int *flag);

void fill_matrix(int *err, int repeat_w, char **matrix, int *q, int j, char *word);

int parce(char *string, char **matrix, int *q);

int sort(char **matrix, int q);

void output(char **matrix, int q);

void word_copy(char *s1, char *s2);
 
#endif