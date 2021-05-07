# Makefile

# Kommando-Variablen

CC = gcc -g
CFLAGS = -W -Wall -std=$(STD) -pedantic
STD = c11

#Hilfsvariablen
OBJECTS=$(TARGET:=.o)
TARGET=filesize filecopy

#Standardziele
.PHONY: all clean

all: $(TARGET)

filesize: filesize.c
	$(CC) $(CFLAGS) -o $@ $^

filecopy: filecopy.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJECTS)
