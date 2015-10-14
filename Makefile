SRC=src/main.c
DEST=virgulino

INSTALL_DIR=/usr/bin

CC=gcc
SWITCH=-o

default:
	$(CC) $(SRC) $(SWITCH) $(DEST)

all: default


clean:
	rm -f $(DEST) 

install:
	cp $(DEST) $(INSTALL_DIR)/

uninstall:
	rm -f $(INSTALL_DIR)/$(DEST)


	

