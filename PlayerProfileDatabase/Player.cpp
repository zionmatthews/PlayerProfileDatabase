#include "pch.h"
#include "Player.h"
#include <iostream>

//default constructer
Player::Player()
{
	strcpy_s(_Name, "Player");
	_Score = 0;
}
//Function that takes the name and score in as int
Player::Player(const char name[30] , int score)
{
	strcpy_s(_Name, name);
	_Score = score;
}

//default constructer
Player::~Player()
{

}
//Get Name
char* Player::getName()
{
	return _Name;
}
//Get Score
int Player::getScore()
{
	return _Score;
}

//set name
void Player::setName(const char name[30])
{
	strcpy_s(_Name, name);
}
//set score
void Player::setScore(const int score)
{
	_Score = score;
}
