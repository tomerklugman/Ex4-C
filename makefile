CC=gcc
AR=ar
FLAGS=-Wall -g

# Makes all.
all: frequency

# Creates .o files and frequency.
frequency: frequency.o trie.o
	$(CC) $(FLAGS) -o frequency frequency.o trie.o

# Links frequency.c and trie.h.
frequency.o: frequency.c trie.h
	$(CC) $(FLAGS) -c frequency.c
	
# Links trie.c and trie.h.
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all 

# Cleans all made files.
clean:
	rm -f *.o *.a *.so frequency

