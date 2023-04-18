#include <stdio.h>
#include"funcs.h"

int my_strcspn(char *origin, char *str)
{
	int q = DNT_MATCH;
	int i = 0;
	int j = 0;
	while ((origin[i] != '\0') && (q == DNT_MATCH))
	{
		while (str[j] != '\0')
		{
			if (origin[i] == str[j])
				q = i;
			j += 1;
		}
		i += 1;
		j = 0;
	}
	if (q == DNT_MATCH)
		q = i;
	return q;
}

