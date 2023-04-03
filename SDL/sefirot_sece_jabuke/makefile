CC = gcc

CFLAGS = -g -Wall `sdl2-config --cflags --libs` -lSDL2_image

TARGET = main

all: $(TARGET)
	$(CC) main.c -o $(TARGET)  $(CFLAGS) 
win: 
	 gcc -Isrc/Include -Lsrc/lib -o sefisece.exe main.c -lSDL2main -lSDL2 -lSDL2_image -mwindows