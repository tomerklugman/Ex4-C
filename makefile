CC=gcc
AR=ar
FLAGS=-Wall -g

all: frequency

frequency: frequency.o trie.o
	$(CC) $(FLAGS) -o frequency frequency.o trie.o
frequency.o: frequency.c trie.h
	$(CC) $(FLAGS) -c frequency.c
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all 

clean:
	rm -f *.o *.a *.so frequency

