#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "funcs.h"

t_list *create_element(char *n, char *reg, char *dist, int popul, int y)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	
	node -> name = malloc(strlen(n) * sizeof(char));
	node -> region = malloc(strlen(reg) * sizeof(char));
	node -> district = malloc(strlen(dist) * sizeof(char));
	
	strcpy(node -> name, n);
	strcpy(node -> region, reg);
	strcpy(node -> district, dist);
	
	node -> population = popul;
	node -> year = y;
	node -> next = NULL;
	
	return node;
}

int read_line(char *string, FILE *file)
{
	int err = OK;
	int length = 0;
	
	if (fgets(string, FIELD_SIZE, file) == NULL)
		err = INPUT_ERR;
	
	if (string[0] == '\n')
		if (fgets(string, FIELD_SIZE, file) == NULL)
			err = INPUT_ERR;
		
		
	if (err == OK)
	{
		length = strlen(string);
		if (string[length - 1] == '\n')
		{
			string[length - 1] = '\0';
			length -= 1;
		}
	}
	if ((length > FIELD_SIZE) || (length == 0))
		err = INPUT_ERR;
	
	return err;
}

void add_back(t_list **list, char *n, char *reg, char *dist, long int popul, int y)
{
	t_list *new_el = create_element(n, reg, dist, popul, y);
	
	if (*list == NULL)
		*list = new_el;
	else
	{
		t_list *tmp = *list;
		while (tmp -> next != NULL)
			tmp = tmp -> next;
		tmp -> next = new_el;
	}
}

void move(t_list **list)
{
	t_list *tmp = *list;
	//t_list *tmp1 = *list;
	t_list *prev = NULL;
	
	t_list *first = NULL;
	t_list *prev_mil = NULL;
	
	/*while (tmp != NULL)
	{
		if (tmp -> population < 1000000)
		{
			first = tmp;
			break;
		}
		prev = tmp;
		tmp = tmp -> next;
	}*/
	
	while (tmp != NULL)
	{
		if ((first != NULL) && (tmp -> population >= 1000000))
		{
			prev -> next = tmp -> next;
			tmp -> next = first;
			if (prev_mil != NULL)
			{
				prev_mil -> next = tmp;
				prev_mil = tmp;
			}
			else
			{
				prev_mil = tmp;
				*list = tmp;
			}
			tmp = prev -> next;
		}
		else
		{
			if ((first == NULL) && (tmp -> population < 1000000))
			{
				first = tmp;
				prev_mil = prev;
				//*list = prev;
			}
			prev = tmp;
			tmp = tmp -> next;
		}
	}
}

int find_cities(t_list **list, t_list **new_list, char *string)
{
	t_list *tmp = *list;
	
	while (tmp != NULL)
	{
		if (strstr(tmp -> name, string) != NULL)
		{
			add_back(new_list, tmp -> name, tmp -> region, tmp -> district, tmp -> population, tmp -> year);
		}
		tmp = tmp -> next;
	}
	return 0;
}

/*
void move(t_list **list)
{
	t_list *tmp = *list;
	t_list *prev = NULL;
	
	while (tmp != NULL)
	{
		if ((prev != NULL) && (tmp -> population >= 1000000))
		{
			prev -> next = tmp -> next;
			tmp -> next = *list;
			*list = tmp;
			tmp = prev -> next;
		}
		else
		{
			prev = tmp;
			tmp = tmp -> next;
		}
	}
}
*/