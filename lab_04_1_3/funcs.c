#include <stdio.h>
#include <string.h>
#include"funcs.h"

int transform(char **matrix, char buffer[][WORD])
{
	for (int i = 0; i < WORD; i++)
	{
		matrix[i] = buffer[i];
	}
	return 0;
}

int input_string(char *string)
{
	int err = 0;
	int length = 0;
	if (fgets(string, M + 1, stdin) == NULL)
		err = 1;
	if (err == 0)
	{
		length = strlen(string);
		if (string[length - 1] != '\n')
			err = 1;
	}
	if (err == 0)
	{
		string[length - 1] = '\0';
		length -= 1;
	}
	if ((length > M) || (length == 0))
		err = 1;
	return err;
}

int check_length(char **matrix, char *word, int q, int *repeat_w)
{
	int err = 0;
	*repeat_w = 0;
	if (strlen(word) > WORD)
		err = 1;
	return err;
}

int check_equal_last(char **matrix, int q)
{
	int i = 0;
	
	while (i < q - 1)
	{
		if (strcmp(matrix[q - 1], matrix[i]) == 0)
		{
			for (int j = i; j < q - 1; j++)
			{
				word_copy(matrix[j], matrix[j + 1]);
			}
			q -= 1;
		}
		else
			i += 1;
	}
	q -= 1;
	return q;
}

int del_letters(char **matrix, int q)
{
	int letter, repeat_w;
	for (int i = 0; i < q; i++)
	{
		letter = 0;
		repeat_w = 0;
		while (letter < strlen(matrix[i]))
		{
			for (int j = 0; (j < letter) && (repeat_w == 0); j++)
				if (matrix[i][j] == matrix[i][letter])
					repeat_w = 1;
			if (repeat_w == 1)
			{
				for (int j = letter; j < strlen(matrix[i]); j++)
					matrix[i][j] = matrix[i][j + 1];
				repeat_w = 0;
			}
			else
				letter += 1;
		}
	}
	return 0;
}

int form_string(char **matrix, int q, char *string)
{
	string[0] = '\0';
	
	for (int i = 0; i < q; i++)
	{
		strncat(string, matrix[i], M);
		if (i < q - 1)
			strncat(string, " ", M);
	}
	return 0;
}

void fill_matrix(int *err, int repeat_w, char **matrix, int *q, int j, char *word)
{
	*err = (check_length(matrix, word, *q, &repeat_w));
	if ((*err == 0) && (repeat_w == 0))
	{
		for (int k = 0; k <= j; k++)
		{
			matrix[*q][k] = word[k];
		}
		*q += 1;
	}
}

int parce(char *string, char **matrix, int *q)
{
	char word[WORD] = "";
	int i = 0, j = 0;
	int repeat_w = 0, err = 0;
	char sep[9] = " ,;:-.!?";
	
	while ((string[i] != '\0') && (err == 0))
	{
		if (strchr(sep, string[i]))
		{
			if (j != 0)
			{
				word[j] = '\0';
				fill_matrix(&err, repeat_w, matrix, q, j, word);
			}
			j = 0;
		}
		else
		{
			word[j] = string[i];
			j += 1;
		}
		i += 1;
	}
	if (j != 0)
		fill_matrix(&err, repeat_w, matrix, q, j, word);
	if (*q < 1)
		err = 1;
	return err;
}

int reverse(char **matrix, int q)
{
	char x[WORD];
	int j = 0;
	for (int i = q - 1; i > j; i--)
	{
		word_copy(x, matrix[i]);
		word_copy(matrix[i], matrix[j]);
		word_copy(matrix[j], x);
		j += 1;
	}
	return 0;
}

void word_copy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i += 1;
	}
	s1[i] = '\0';
}

void output(char **matrix, int q)
{
	for (int i = 0; i < q; i++)
	{
		printf("%s ", matrix[i]);
	}
	printf("\n");
}