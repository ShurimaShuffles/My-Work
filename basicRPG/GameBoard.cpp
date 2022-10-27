#include "GameBoard.h"
#include <iostream>
using namespace std;

// Is the function that creates the game board.
vector<char> GameBoard::resetGrid(vector<char> grid){
	for(int j = 0; j < yMax; j++){
		for(int i = 0; i < xMax; i++){
			grid.push_back('.');
		}

		grid.push_back('|');

		for(int i = 0; i < xMax; i++){
			grid.push_back('.');
		}
	}

	for(int i = 0; i < (xMax * 2 +1); i++){
		grid.push_back('_');
	}

	for(int j = 0; j < yMax; j++){
		for(int i = 0; i < xMax; i++){
			grid.push_back('.');
		}

		grid.push_back('|');

		for(int i = 0; i < xMax; i++){
			grid.push_back('.');
		}
	}
	return grid;
}

// Construscts the GameBoard with max x,y
GameBoard::GameBoard(int x, int y){ // constructed once
	xMax = x;
	yMax = y;
	grid = resetGrid(grid);

}

//Adds an enemy to the vector of enemies.
void GameBoard::addGamePiece(Enemy*& foe){
	foeList.push_back(foe);
}

//Displays a board of x by y filled with enemies.
//Will say oops if enemies walk out of bounds.///////////
// Can't be of type Const because of line 63 for proper printing of enemies.
void GameBoard::printBoard(){
	int tempX;
	int tempY;
	int foeLocation;

	//Converts x,y locations to a vector location.
	for (int i = 0; i < foeList.size(); i++){


	for(int j = 0; j < foeList.size(); j++){
		if(foeList[i]->getX() == foeList[j]->getX() and foeList[i]->getY() == foeList[j]->getY() and i != j){
			cout << "\tBeware, someone is already in this space!" << endl;
		}
	}



	//Checks to see where the enemies are and if they are valid positions.
	if(foeList[i]->getX() > xMax){
		cout << "\tOops, would have stepped off the grid on pos X!" << endl;
		foeList[i]->setX(xMax);
	}
	if(foeList[i]->getX() < (-1 * xMax)){
		cout <<"\tOops, would have stepped off the grid on neg X!" << endl;
		foeList[i]->setX((-1 * xMax));
	}


	if(foeList[i]->getY() > yMax){
		cout <<"\tOops, would have stepped off the grid on pos Y!" << endl;
		foeList[i]->setY(yMax);
	}
	if(foeList[i]->getY() < (-1 * yMax)){
		cout <<"\tOops, would have stepped off the grid on neg Y!" << endl;
		foeList[i]->setY((-1 * yMax));
	}




		//Makes temp variable and converts x and y into indexs on the vector.
		tempX = foeList[i]->getX() + xMax;
		tempY = foeList[i]->getY() - yMax;
		
		if(tempY < 0){
			tempY = tempY *(-1);
		}

		foeLocation = (2 * xMax + 1) * tempY + tempX;
		grid[foeLocation] = foeList[i]->getDisplayChar();
	}

	
	//Prints out the grid the enemies are displayed on.
	int crSpot = (2 * xMax)+1;
	for(int i = 0; i < grid.size(); i++){
		if ((i % crSpot == 0) and i > 0){
			cout << endl;
		}
		cout << grid[i];
	}
}

//delete everything inside the vectors and resets the board.
void GameBoard::resetBoard(){
	foeList.erase( foeList.begin(), foeList.end());
	grid.erase( grid.begin(), grid.end());
	grid = resetGrid(grid);
}
