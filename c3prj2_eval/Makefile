CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99 -g
GIVEN_OBJS=deck.o  eval.o  future.o  input.o  main.o test-eval.o


test-eval: eval.o test-eval.o deck.o cards.o input.o future.o
	gcc -no-pie -o test-eval -ggdb3 deck.o eval.o test-eval.o cards.o input.o future.o
poker: $(GIVEN_OBJS) 
	gcc -o poker -ggdb3  $(GIVEN_OBJS)
clean:
	rm -f test poker cards.o my-test-main.o *~

