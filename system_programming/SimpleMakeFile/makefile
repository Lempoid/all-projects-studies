CC = gcc
INCLUDE_DIR = ../include
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -I$(INCLUDE_DIR)
GD = $(CC) $(CFLAGS) 

TARGET = ./fooer.out
LIBRARY = ./libfoo.ar
SRC_DIR = ../src
TEST_DIR = ../test

SRC_FILES = $(SRC_DIR)/foo.c
TEST_FILES = $(TEST_DIR)/main.c
OBJ_FILES = $(SRC_FILES:.c=.o) $(TEST_FILES:.c=.o)
LIB_FIELS = $(SRC_FILES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(GD) -o $@ $^

$(LIBRARY): $(LIB_FIELS)
	ar rcs $< $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(GD) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(GD) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)

debug: CFLAGS += -g

release: CFLAGS += -02

.PHONY: all clean debug release