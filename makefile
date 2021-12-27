CC = gcc
CFLAGS  = -g -Wall
LINKING = -lglut -lGL -lGLU
TARGET = 3d_house

all:
	$(CC) $(CFLAGS) -o out $(TARGET).c $(LINKING)
	./out
