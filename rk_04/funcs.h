#ifndef __FUNCS_H__
#define __FUNCS_H__

#define OK 0
#define INPUT_ERR -1

#define FIELD_SIZE 30

typedef struct s_list{
	char *name;
	char *region;
	char *district;
	long int population;
	int year;
	
	struct s_list *next;
	
}t_list;

t_list *create_element(char *n, char *reg, char *dist, int popul, int y);

int read_line(char *string, FILE *file);

void add_back(t_list **list, char *n, char *reg, char *dist, long int popul, int y);

void move(t_list **list);

int find_cities(t_list **list, t_list **new_list, char *string);


#endif