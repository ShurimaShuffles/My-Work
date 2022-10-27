#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "Goblin.h"
using namespace std;

/*
Brandon Lavoie April 23, 2022

This is the implementation of the class Goblin. 
It contains the implementations for the virtual 
classes defined in its parent. This allows the
Goblin type objects to have different attack
injure and update methods compared to the 
Troll and Orc classes.
*/
Goblin::Goblin(int hp, int str, int con, int xPos, int yPos): Enemy(hp, str, con, xPos, yPos)
{
	cout <<	"Goblin" << " " << id << " @ " << "(" << xPosition
	<< ", " << yPosition << ") hp = " << health << endl;
}

// Updates Goblin's position.
void Goblin::update() {
	if(alive){
		xPosition = xPosition + rand() % 3 + -3;
		yPosition = yPosition + rand() % 2 + -2;
	}
}

// Prints the Goblin's stats and position.
void Goblin::print() const{
       
	cout << "Goblin" << " " << id <<" @ (" << xPosition << ", " << yPosition 
	<< ") hp = " << health << endl;
}

// Prints Goblin's attack on a peasent.
void Goblin::attack() const{

	cout << "Goblin" << " " << id << " attacks a random passerby for " 
	<< str + rand() % 4 + 1 << " damage!" << endl; 
}

//Changes Goblin's hp based on the value passed.
void Goblin::injure(int damage) {
	int defDmg = 0;

	defDmg = damage - con / 2;
	if(defDmg >= 0){
		health = health - defDmg;
	}

	if(defDmg <= 0){
		cout << "The passerby tries to attack " << "Goblin" << " " << id 
		<< ", but it isn't very effective...\n" << endl; 
	}

	else if(health <= 0){
		alive = false;
		cout << "Goblin" << " " << id << " has been slain!\n" << endl;
	}

	else{
		cout << "Goblin" << " " << id << " takes " 
		<< defDmg << " damage! Current hp = " << health << "\n" << endl;
	}
}

//Returns the type of enemy
const char Goblin::getDisplayChar() const{
	if (alive){
		return 'G';
	}
	else{
		return 'g';
	}
}




