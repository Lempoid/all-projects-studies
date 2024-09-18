GD = gcc -ansi -pedantic-errors -Wall -Wextra -g

TARGET = fooer.out
IDIR = ../include
SDIR = ../src
TDIR = ../test

SRC = $(SDIR)/foo.c $(TDIR)/main.c
OBJ = 

%.o: %.c $(DEPS)
	$(GD) -c -o $@ $<


: $(OBJ)
	$(GD) -o $@ $^

