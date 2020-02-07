#include "pch.h"
#include "Player.h"
#include <iostream>


Player::Player()
{
	strcpy_s(Name, "Player");
	Score = 0;
}

Player::Player(char* name, int score)
{
	strcpy_s(Name, name);
	Score = score;
}


Player::~Player()
{

}

char* Player::getName()
{
	return Name;
}

int Player::getScore()
{
	return Score;
}

//set name
void Player::setName(const char name[30])
{
	strcpy_s(Name, name);
}
//set score
void Player::setScore(const int score)
{
	Score = score;
}

void Player::editPlayerName(char* name)
{
	name = Name;
}