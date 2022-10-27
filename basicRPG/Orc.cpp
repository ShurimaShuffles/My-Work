#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "Orc.h"
using namespace std;

/*
Brandon Lavoie April 23, 2022

This is the implementation of the class Orc. 
It contains the implementations for the virtual 
classes defined in its parent. This allows the
Orc type objects to have different attack
injure and update methods compared to the 
Troll and Goblin classes.
*/
Orc::Orc(int hp, int str, int con, int xPos, int yPos): Enemy(hp, str, con, xPos, yPos)
{
	cout <<	"Orc" << " " << id << " @ " << "(" << xPosition
	<< ", " << yPosition << ") hp = " << health << endl;
}

// Updates Orc's position.
void Orc::update() {
	if(alive){
		int randDist = rand() % 5 + -5;
		xPosition = xPosition + randDist;
		yPosition = yPosition + randDist;
	}
}

// Prints the Orc's stats and position.
void Orc::print() const{
       
	cout << "Orc" << " " << id <<" @ (" << xPosition << ", " << yPosition 
	<< ") hp = " << health << endl;
}

// Prints Orc's attack on a peasent.
void Orc::attack() const{

	cout << "Orc" << " " << id << " attacks a random passerby for " 
	<< str + rand() % 4 + 1 << " damage!" << endl; 
}

//Changes Orc's hp based on the value passed.
void Orc::injure(int damage) {
	int defDmg = 0;

	defDmg = damage - con;
	if(defDmg >= 0){
		health = health - defDmg;
	}

	if(defDmg <= 0){
		cout << "The passerby tries to attack " << "Orc" << " " << id 
		<< ", but it isn't very effective...\n" << endl; 
	}

	else if(health <= 0){
		alive = false;
		cout << "Orc" << " " << id << " has been slain!\n" << endl;
	}

	else{
		cout << "Orc" << " " << id << " takes " 
		<< defDmg << " damage! Current hp = " << health << "\n" << endl;
	}
}

//Returns the type of enemy
const char Orc::getDisplayChar() const{
	if (alive){
		return 'O';
	}
	else{
		return 'o';
	}
}




