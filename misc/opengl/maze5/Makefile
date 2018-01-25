CC=g++
#CFLAGS=-c -Wall
#LIBS=-lGL -lGLU -lglut -lX11 -lpng -lz -lm
#OBJS=main.o Model.o Robot.o Maze.o Player.o Bullet.o

#all: test

#test: main.o Model.o Robot.o Maze.o Player.o Bullet.o
#	$(CC) main.o Model.o Robot.o Maze.o Player.o Bullet.o -o test

#main.o: main.cpp
#	$(CC) $(CFLAGS) main.cpp $(LIBS)

#Model.o: Model.cpp
#	$(CC) $(CFLAGS) Model.cpp $(LIBS)

#Robot.o: Robot.cpp
#	$(CC) $(CFLAGS) Robot.cpp $(LIBS)

#Maze.o: Maze.cpp
#	$(CC) $(CFLAGS) Maze.cpp $(LIBS)

#Player.o: Player.cpp
#	$(CC) $(CFLAGS) Player.cpp $(LIBS)

#Bullet.o: Bullet.cpp
#	$(CC) $(CFLAGS) Bullet.cpp $(LIBS)

#clean:
#	rm *.o

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lGL -lglut -lGLU

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog
