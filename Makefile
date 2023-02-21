# GROUP 8

# Jalen Duggan - 100713924
# Mohammed Khan - 100756901
# Rayan Pasha - 100704599

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LFLAGS = 
LIBS = -lm
SOURCES = myshell.c utility.c
OBJECTS = $(subst .c,.o,$(SOURCES))
BIN = myshell
.PHONY: clean help
 

%.o : %.c
	$(CC) $(CFLAGS) -c $< 

all : $(BIN)

myshell: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	rm -f $(OBJECTS) $(BIN) *~

help:
	@echo "Valid targets:"
	@echo "  clean:  removes .o and binary files"
