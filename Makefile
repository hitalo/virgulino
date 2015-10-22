SRC=src/main.c
DEST=virgulino
DESTDIR=/usr/bin/
CC=gcc
SWITCH=-o

default:
	$(CC) $(SRC) $(SWITCH) $(DEST)

all: default


clean:
	rm -f $(DEST) 

install:
	mv $(DEST) $(DESTDIR)

uninstall:
	rm -f $(DESTDIR)/$(DEST)


	

