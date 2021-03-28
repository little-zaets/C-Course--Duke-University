CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99 -g

MY_OBJS=cards.o deck.o eval.o testdeck.o

testdeck: deck.o eval.o cards.o testdeck.o
	gcc -o testdeck -ggdb3 deck.o cards.o eval.o testdeck.o
poker: $(GIVEN_OBJS) $(MY_OBJS)
	gcc -o poker -ggdb3  $(MY_OBJS)
clean:
	rm -f test poker cards.o my-test-main.o *~

