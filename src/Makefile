CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I../include
OBJDIR = ../obj
BINDIR = ../bin

OBJS = $(OBJDIR)/main.o $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
TARGET = $(BINDIR)/client

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(OBJS) -o $(TARGET)

$(OBJDIR)/main.o: main.c ../include/mystrfunctions.h ../include/myfilefunctions.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c main.c -o $@

$(OBJDIR)/mystrfunctions.o: mystrfunctions.c ../include/mystrfunctions.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $@

$(OBJDIR)/myfilefunctions.o: myfilefunctions.c ../include/myfilefunctions.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $@

clean:
	rm -f $(OBJS) $(TARGET)
