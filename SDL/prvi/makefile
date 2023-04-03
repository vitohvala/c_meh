
CC = gcc

CFLAGS = -g -Wall `sdl2-config --cflags --libs`

TARGET = main


all: $(TARGET)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
win:
	gcc -Isrc/Include -Lsrc/lib -o winb.exe main.c -lSDL2main -lSDL2 -mwindows
