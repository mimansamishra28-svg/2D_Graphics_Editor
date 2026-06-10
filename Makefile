CC = gcc
CFLAGS = -Iinclude -Wall

all:
	$(CC) $(CFLAGS) src/main.c src/canvas.c src/shapes.c src/menu.c -o build/editor

clean:
	del build\editor.exe