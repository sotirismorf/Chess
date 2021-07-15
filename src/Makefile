cc = g++
cflags = -Wall -g
executable = main
objects = main.o player.o piece.o board.o square.o
lib = -lsfml-graphics -lsfml-window -lsfml-system

edit : $(objects)
	$(cc) $(cflags) -o $(executable) $(objects) $(lib)

main.o : piece.h board.h player.h
piece.o : piece.h
board.o : board.h square.h
square.o : square.h
player.o : player.h piece.h

.PHONY : clean
clean :
		rm $(executable) $(objects)
