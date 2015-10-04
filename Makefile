SRC=src/main.c
DEST=main

CC=gcc
SWITCH=-o

default:
	$(CC) $(SRC) $(SWITCH) $(DEST)

all: default

clean:
	rm -f $(DEST) 
