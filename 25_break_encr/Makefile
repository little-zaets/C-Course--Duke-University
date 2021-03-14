CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99

.DEFAULT_GOAL := breaker

breaker: 
	$(CC) -o breaker $(CFLAGS) breaker.c

.PHONY: clean

clean:
	rm -f breaker breaker.o	