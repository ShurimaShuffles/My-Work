#include <iostream>
#include "Enemy.h"
using namespace std;

/*
Brandon Lavoie April 19, 2022

This is the implementation of the super class Enemy. 
It contains the isAlive function and other getters and setters. 
The rest of the class is virtual.
*/

Enemy::Enemy(int hp, int str,int con, int xPos, int yPos){
	this->health = hp;
	this->str = str;
	this->con = con;
	this->xPosition = xPos;
	this->yPosition = yPos;
	this->alive = true;
	static int idGenerator = 0;
	id = idGenerator++;
	
}

//Getters
int Enemy::getId() const{
	return this->id;
}
int Enemy::getHealth() const{
	return this->health;	
}
int Enemy::getStr() const{
	return this->str;
}
int Enemy::getCon() const{
	return this->con;
}
int Enemy::getX() const{
	return this->xPosition;
}
int Enemy::getY() const{
	return this->yPosition;
}
bool Enemy::isAlive() const{
	return this->alive;
}

//Setters 

void Enemy::setX(int xPos){
	this->xPosition = xPos;
}
void Enemy::setY(int yPos){
	this->yPosition = yPos;
}


