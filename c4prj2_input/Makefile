CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99 -g

MY_OBJS=cards.o deck.o eval.o input.o future.o test-input.o

test-future: deck.o eval.o cards.o future.o input.o test-input.o
	gcc -o test-input -ggdb3 deck.o cards.o eval.o future.o input.o test-input.o
poker: $(MY_OBJS)
	gcc -o poker -ggdb3  $(MY_OBJS)
clean:
	rm -f test poker cards.o test-input.o *~