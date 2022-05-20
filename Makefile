connectn.out: board.o game.o input_validation.o main.o win.o
	gcc -g -Wall -Werror -o connectn.out board.o game.o input_validation.o main.o win.o

board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c

game.o: game.c game.h board.h input_validation.h win.h
	gcc -g -Wall -Werror -c game.c

input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c

main.o: main.c game.h board.h input_validation.h win.h
	gcc -g -Wall -Werror -c main.c

win.o: win.c win.h board.h game.h
	gcc -g -Wall -Werror -c win.c

clean:
	rm -rf *.o *.out
