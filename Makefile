SRC=src/main.c
DEST=virgulino
DESTDIR=/usr/bin/
CC=gcc
SWITCH=-o
CVERSION=-std=c11
DOC_FILE_1=virgulino.1
DOC_SOURCE=doc/
DOC_DEST_1=/usr/share/man/man1

default:
	$(CC) $(SRC) $(CVERSION) $(SWITCH) $(DEST)

all: default


clean:
	rm -f $(DEST) 

install:
	mv $(DEST) $(DESTDIR)
	cp $(DOC_SOURCE)/$(DOC_FILE_1) $(DOC_DEST_1)

uninstall:
	rm -f $(DESTDIR)/$(DEST)

