CFLAGS = -Wall -fpic -coverage -lm -std=c99

all: testme.c
	gcc -o testme testme.c $(CFLAGS)

run: 
	./testme

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out