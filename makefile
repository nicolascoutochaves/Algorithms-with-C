all: clean mem

map: map_generator.c
	gcc -o map_generator.o map_generator.c

test: test.c
	gcc -o test.o test.c -lraylib

mem: mem.c
	gcc -o mem.o mem.c; ./mem.o

clean:
	rm -f mem.o test.o map_generator.o