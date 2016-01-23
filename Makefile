SRC=src/main.c
DEST=virgulino
DESTDIR=/usr/bin/
CC=gcc
SWITCH=-o
CVERSION=-std=c11

default:
	$(CC) $(SRC) $(CVERSION) $(SWITCH) $(DEST)

all: default


clean:
	rm -f $(DEST) 

install:
	mv $(DEST) $(DESTDIR)

uninstall:
	rm -f $(DESTDIR)/$(DEST)


	

