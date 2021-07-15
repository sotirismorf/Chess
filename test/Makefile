cc = g++
objects = main.o piece.o

edit : $(objects)
		$(cc) -o edit $(objects)

main.o : piece.h
piece.o : piece.h

.PHONY : clean
clean :
		rm edit $(objects)
