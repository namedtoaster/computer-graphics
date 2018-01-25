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




# The above commented out Makefile was an original attempt. I'm still
# not exactly sure why it doesn't work. But according to a tutorial I
# found online, what I have below is what will be used most of the
# time. The thing that got me about this Makefile was that there were
# no rules for compiling the object files. Apparently, GNU make is
# smart enough to be able to do that for all the cpp (or c files, etc)
# in the current directory. The only thing you need to do is create a
# rule that links all object files together as shown below

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lGL -lglut -lGLU
IDIR =../include
CFLAGS=-I$(IDIR)

# See
# https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
# for explanation on what the $@ and @^ variables do.
#
# The '$@' variable is the string for the target (myprog in this case)
# and the '$^' variable is the names of all the prerequisites with
# spaces between all of them (the $(obj) variable in this case)

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog
