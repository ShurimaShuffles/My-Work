/* 
Programer: Brandon Lavoie
Class: CS 360 Spring 2022
Assignment: 1

This is the .cpp file that has all of the method implimentations that the WordleBoard class will call.
It has the constructor, destructor and a way to take inputs (takes a string that is a guess)
then adds it to a 2d array. Then will print the board in accordance to the wordle color scheme
after each guess.
*/

#include "WordleBoard.h"
#include <iostream>
#include <string>
using namespace std;

WordleBoard::WordleBoard(string word){
    for(int i = 0; i < 6; i++){
		for( int j = 0; j < 5; j++){
        	guessList[i][j] = "_";
		}
    }
    guessNum = 0;
	gameWord = word;
}

// If the player lost when the board is out of scope, displays the loss message.
WordleBoard::~WordleBoard(){
	if(guessNum == 6){
    	cout << "You Lost!\n" << "The word was: " << gameWord << "\n";
	}
}


int WordleBoard::getGuessNum(){
	return this->guessNum;
}


void WordleBoard::setGuess(string guess){
	
	// parsing through the guess to see if the letter is in the correct spot or in the word at all.
	for(int i = 0; i < 5; i++){
		string guessChar(1,guess.at(i));
		for(int j = 0; j<5; j++){
			if(guess.at(i) == gameWord.at(i)){
				guessChar = "\033[0;32m" + guessChar + "\033[0m";
			}
			else if(guess.at(i) == gameWord.at(j)){
				guessChar = "\033[0;33m" + guessChar + "\033[0m";
			}
		}
			guessList[guessNum][i] = guessChar;		
	}
    guessNum++;
}

// Prints the newly altared guesses made by the user.
void WordleBoard::printGuesses(){

	for(int i = 0; i < 6; i++){
		cout << i + 1 << " " <<  guessList[i][0] << " " << guessList[i][1] << " " << guessList[i][2] << " " << guessList[i][3] << " " << guessList[i][4] << "\n";
	}







/*
	for(int k = 0; k < sizeof(guessList) -1; k++){
		
		//Check first letter to see if green or not
		for(int i = 0; i < 5; i++){
			if(gameWord.at(i) == guessList[k].at(i)){

				string guess(1,guessList[k].at(i));
				guess = "\033[0;32m" + guess + "\033[0m"; // make dynamic and for all letters!
			}
		}
		
        cout << k + 1 << " " << guess0 << " " << guessList[k].at(1) << " " << guessList[k].at(2) << " " << guessList[k].at(3) << " " << guessList[k].at(4) << "\n";
    }
*/
}
