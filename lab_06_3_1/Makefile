main.o: main.c
	gcc -std=c99 -Wall -Wextra -Werror -pedantic -O0 -fprofile-arcs -ftest-coverage -Wvla -Wfloat-equal -Wfloat-conversion -c main.c -o main.o
	
funcs.o: funcs.c
	gcc -std=c99 -Wall -Wextra -Werror -pedantic -O0 -fprofile-arcs -ftest-coverage -Wvla -Wfloat-equal -Wfloat-conversion -c funcs.c -o funcs.o
	
main.exe: main.o funcs.o
	gcc -std=c99 -Wall -Wextra -Werror -pedantic -O0 -fprofile-arcs -ftest-coverage -Wvla -Wfloat-equal -Wfloat-conversion main.o funcs.o -o main.exe