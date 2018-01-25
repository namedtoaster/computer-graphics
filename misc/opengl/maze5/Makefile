CC=g++
CFLAGS=-c -Wall
LIBS=-lGL -lGLU -lglut

all: test

test: main.o Bullet.o Light.o Maze.o Model.o Player.o Robot.o Surface.o
	$(CC) main.o Bullet.o Light.o Maze.o Model.o Player.o Robot.o
	Surface.o -o test $(LIBS)

main.o: main.cpp Objects.h Room.h Constants.h Surface.h
	$(CC) $(CFLAGS) main.cpp

Bullet.o: Bullet.cpp Bullet.h Constants.h Prototypes.h
	$(CC) $(CFLAGS) Bullet.cpp

Light.o: Light.cpp
	$(CC) $(CFLAGS) Light.cpp

Maze.o: Maze.cpp
	$(CC) $(CFLAGS) Maze.cpp

Model.o: Model.cpp
	$(CC) $(CFLAGS) Model.cpp

Player.o: Player.cpp Player.cpp
	$(CC) $(CFLAGS) Player.cpp

Robot.o: Robot.cpp
	$(CC) $(CFLAGS) Robot.cpp

Surface.o: Surface.cpp
	$(CC) $(CFLAGS) Surface.cpp

clean:
	rm *o test
