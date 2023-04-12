CC=cc
FLAGS=-Wall -g -pedantic -Werror
BINS=snake libtastatura.so 

all: $(BINS)

libtastatura.o: libtastatura.c libtastatura.h
	$(CC) $(FLAGS) -c libtastatura.c

libtastatura.so: libtastatura.c libtastatura.h
	$(CC) $(FLAGS) -fPIC -shared -o $@ libtastatura.c -lc

snake: snake.c libtastatura.o
	$(CC) $(FLAGS) -o $@ $^

runtime: snake.c
	 $(CC) $(FLAGS) -o $@ $^ -L. -ltastatura

clean:
	rm *.o $(BINS) 
