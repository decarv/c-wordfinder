
CC=gcc
CFLAGS=-O2

all: main.c lists.o strings.o sort.o hashmap.o stack.o subsets.o input.o
	$(CC) $(CFLAGS) lists.o strings.o sort.o hashmap.o stack.o subsets.o input.o main.c -o wf

strings.o: strings.c
	$(CC) $(CFLAGS) -c strings.c

input.o: input.c
	$(CC) $(CFLAGS) -c input.c

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c

hashmap.o: hashmap.c
	$(CC) $(CFLAGS) -c hashmap.c

lists.o: lists.c
	$(CC) $(CFLAGS) -c lists.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

subsets.o: subsets.c
	$(CC) $(CFLAGS) -c subsets.c
	
clean:
	rm *.o wf
