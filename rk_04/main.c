#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "funcs.h"


int main(int argc, char *argv[])
{
	int err = OK;
	
	char n[FIELD_SIZE];
	char reg[FIELD_SIZE];
	char dist[FIELD_SIZE];
	long int popul;
	int y;
	
	//char t_str[FIELD_SIZE];
	char f_str[FIELD_SIZE];
	
	FILE *file = fopen(argv[1], "r");
	
	
	t_list *list = NULL;
	t_list *new_list = NULL;
	strcpy(n, "");
	
	while ((err == OK) && (strcmp("end", n) != 0))
	{
		err = read_line(n, file);
		if ((err == OK) && (strcmp("end", n) != 0))
		{
			err = read_line(reg, file);
			if (err == OK)
				err = read_line(dist, file);
			if (err == OK)
				if (fscanf(file, "%ld", &popul) != 1)
					err = INPUT_ERR;
			if (err == OK)
				if (fscanf(file, "%d", &y) != 1)
					err = INPUT_ERR;
			/*if (err == OK)
				err = read_line(t_str, file);*/
				
			if (err == OK)
				add_back(&list, n, reg, dist, popul, y);
			//printf("%s\n%s\n%s\n%ld\n%d\n", n, reg, dist, popul, y);
		}
	}
	
	if (err == OK)
		move(&list);
	
	err = read_line(f_str, stdin);
	
	if (err == OK)
		find_cities(&list, &new_list, f_str);
	
	//printf("\n");
	
	while (list != NULL)
	{
		printf("%s\n%s\n%s\n%ld\n%d\n", list -> name, list -> region, list -> district, list -> population, list -> year);
		list = list -> next;
	}
	printf("end\n");
	
	while (new_list != NULL)
	{
		printf("%s\n%s\n%s\n%ld\n%d\n", new_list -> name, new_list -> region, new_list -> district, new_list -> population, new_list -> year);
		new_list = new_list -> next;
	}
	fclose(file);
	
	return err;
}