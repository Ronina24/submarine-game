battle: main.o board.o check.o game.o
	gcc main.o board.o check.o game.o -o battle

main.o: main.c game.h check.h board.h
	gcc -c main.c

board.o: board.c board.h check.h game.h
	gcc -c board.c

check.o: check.c check.h
	gcc -c check.c

game.o: game.c game.h board.h
	gcc -c game.c