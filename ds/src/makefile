CC = gcc
CFLAGS = -I./include

all: app

app: src/Stack/stack.c test/Stack/main.c
    $(CC) $(CFLAGS) -o app src/Stack/stack.c test/Stack/main.c

clean:
    rm -f app
