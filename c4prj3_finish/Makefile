CC=gcc
CFLAGS=-Wall -Werror -ggdb3 -std=gnu99 -pedantic -g $(OTHERFLAGS)
poker: cards.o  deck.o  eval.o  future.o  input.o  main.o
		gcc -o $@ $(CFLAGS) $^
clean:
		rm -rf *.o poker *~

