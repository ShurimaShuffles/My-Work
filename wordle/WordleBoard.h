/* 
Programer: Brandon Lavoie
Class: CS 360 Spring 2022
Assignment: 1

This is the .h file that has all of the methods that the WordleBoard class will call.
It has the constructor, destructor and a way to take inputs and to print the board
after each guess.
*/
#ifndef WORDLEBOARD_H
#define WORDLEBOARD_H

#include <string>
using namespace std;
class WordleBoard {

	private:
		string guessList[6][5];
		string gameWord;
		int guessNum;
		
	public:
		WordleBoard();
		WordleBoard(string word);
		~WordleBoard();

		int getGuessNum();
		void setGuess(string guess);
		void printGuesses();
};
#endif
