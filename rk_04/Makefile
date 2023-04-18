main.o: main.c
	gcc -std=c99 -Wall -Werror -O0 -c main.c -o main.o
	
funcs.o: funcs.c
	gcc -std=c99 -Wall -Werror -O0 -c funcs.c -o funcs.o
	
main.exe: main.o funcs.o
	gcc -std=c99 -Wall -Werror -O0 main.o funcs.o -o main.exe