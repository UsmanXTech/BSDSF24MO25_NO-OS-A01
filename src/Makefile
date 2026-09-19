CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I../include
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib

LIB_OBJS = $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
MAIN_OBJ = $(OBJDIR)/main.o
LIBRARY = $(LIBDIR)/libmyutils.a
TARGET = $(BINDIR)/client_static

.PHONY: all clean

all: $(TARGET)

$(LIBRARY): $(LIB_OBJS)
	mkdir -p $(LIBDIR)
	ar rcs $(LIBRARY) $(LIB_OBJS)
	ranlib $(LIBRARY)

$(TARGET): $(MAIN_OBJ) $(LIBRARY)
	mkdir -p $(BINDIR)
	$(CC) $(MAIN_OBJ) -L$(LIBDIR) -lmyutils -o $(TARGET)

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
	rm -f $(LIB_OBJS) $(MAIN_OBJ) $(LIBRARY) $(TARGET)
