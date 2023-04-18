main.o: main.c
	gcc -std=c99 -Wall -Werror -pedantic -O0 -c main.c -o main.o
	
funcs.o: funcs.c
	gcc -std=c99 -Wall -Werror -pedantic -O0 -c funcs.c -o funcs.o
	
app.exe: main.o funcs.o
	gcc -std=c99 -Wall -Werror -pedantic -O0 main.o funcs.o -o app.exe