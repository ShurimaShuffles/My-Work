#include <vector>
#include "Enemy.h"
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard{

	private:
		int xMax;
		int yMax;

		std::vector<Enemy*> foeList;
		std::vector<char> grid;
		std::vector<char> resetGrid(std::vector<char> );

	public:
		GameBoard(int, int);
		void addGamePiece(Enemy*&);
		void printBoard();
		void resetBoard();
	
};//end of class

#endif

