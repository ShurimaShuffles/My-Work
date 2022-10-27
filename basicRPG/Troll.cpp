#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "Troll.h"
using namespace std;

/*
Brandon Lavoie April 23, 2022

This is the implementation of the class Troll. 
It contains the implementations for the virtual 
classes defined in its parent. This allows the
Troll type objects to have different attack
injure and update methods compared to the 
Troll and Orc classes.
*/
Troll::Troll(int hp, int str, int con, int xPos, int yPos): Enemy(hp, str, con, xPos, yPos)
{
	maxHealth = hp;
	cout <<	"Troll" << " " << id << " @ " << "(" << xPosition
	<< ", " << yPosition << ") hp = " << health << endl;
}

// Updates Troll's position.
void Troll::update() {
	if(alive){
		int healAmount;
		if(rand() % 2 + 1 == 2){
			xPosition = xPosition + rand() % 10 + 7;
		}
		else{
			xPosition = xPosition + rand() % -7 + -10;
		}

		// Heal if below max hp, if over max hp set to max hp
		if(health < maxHealth){
			if(health + con > maxHealth){
				healAmount = maxHealth - health;			
				health = maxHealth;		
			}
			else{
				healAmount = con;
				health = health + con;
			}
			cout << "Troll" << " " << id << " regenerated " << healAmount
			<< " hp! Current hp = " << health << endl;
		}
	}
}

// Prints the Troll's stats and position.
void Troll::print() const{
       
	cout << "Troll" << " " << id <<" @ (" << xPosition << ", " << yPosition 
	<< ") hp = " << health << endl;
}

// Prints Troll's attack on a peasent.
void Troll::attack() const{

	cout << "Troll" << " " << id << " attacks a random passerby for " 
	<< str + rand() % 8 + 1 << " damage!" << endl; 
}

//Changes Troll's hp based on the value passed.
void Troll::injure(int damage) {
	int defDmg = 0;

	defDmg = damage - (con + (con / 2));
	if(defDmg >= 0){
		health = health - defDmg;
	}

	if(defDmg <= 0){
		cout << "The passerby tries to attack " << "Troll" << " " << id 
		<< ", but it isn't very effective...\n" << endl; 
	}

	else if(health <= 0){
		alive = false;
		cout << "Troll" << " " << id << " has been slain!\n" << endl;
	}

	else{
		cout << "Troll" << " " << id << " takes " 
		<< defDmg << " damage! Current hp = " << health << "\n" << endl;
	}
}

//Returns the type of enemy
const char Troll::getDisplayChar() const{
	if (alive){
		return 'T';
	}
	else{
		return 't';
	}
}
