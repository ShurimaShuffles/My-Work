/* 
Programer: Brandon Lavoie
Class: CS 360 Spring 2022
Assignment: 1

The main file for this assingment will govern the execution of the popular game Wordle.
It will do this by calling a custom class called WordleBoard which will save up to six
guesses made by the user and let the user know if the letters they used in their guess are
in the word, in the correct spot, or not in the word at all. The program does this by
being passed a file of five letter words then comparing the guesses made by the user
to said words written in the file.
*/

#include "WordleBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

int main() {

vector<string> wordList;
string word;
string gameWord;
string guess;
bool isWord = false;
bool isGameWord = false;
int n = 0;

// reads in file of five letter words.
ifstream readFile("sgb-words.txt");
while(getline (readFile, word)){
	wordList.push_back(word);
}
readFile.close();

//selects word for the game. via random time seed.
srand (time(NULL));
gameWord = wordList[rand() % (wordList.size())];
WordleBoard game(gameWord);

cout << "Welcome to EOU Wordle!\n";

// Loop till end of game. (six guesses or till word is guessed)
while(game.getGuessNum() < 6){

	//User input
	cout << "Enter a word: ";
	getline(cin, guess);

		

		//Loop to validate word choice.
		while(!isWord){
			for(string check : wordList){
				if(guess == check){
					isWord = true;
				}
			}

			if(isWord){
				isWord = false;
				break;
			}

			cout << "Please enter a real five letter word!\n";
			cout << "Enter a word: ";
			getline(cin, guess);
		}


	game.setGuess(guess);
	game.printGuesses();

	if(guess == gameWord){
		cout << "You Win!!\n";
		return 0;
	}
}
}
