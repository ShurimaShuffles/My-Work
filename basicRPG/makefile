CC=g++
CFLAGS=-std=c++0x -I.
DEPS = Enemy.h GameBoard.h Goblin.h Orc.h Troll.h
OBJ = Enemy.o GameBoard.o Goblin.o Orc.o Troll.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tidy:
	rm -f *.o core

clean:
	rm -f *.o core game
