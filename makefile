all: test

map: map_generator.c
	gcc -o map_generator.o map_generator.c

test: test.c
	gcc -o test.o test.c -lraylib
