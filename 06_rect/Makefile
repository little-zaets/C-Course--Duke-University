CC = gcc
CFLAGS = -pedantic -std=gnu99 -Wall -Werror 

rectangle: rectangle.o
	gcc -o rectangle rectangle.o
rectangle.o: rectangle.c
	gcc $(CFLAGS) -c rectangle.c
