# Makefile
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o funcoes.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

restaurant: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o restaurant
