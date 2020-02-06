all: assignment1

assignment1: assignment1.c
	gcc -o run assignment1.c

clean: clean_all

clean_all:
	rm -f run