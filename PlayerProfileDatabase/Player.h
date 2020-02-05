#pragma once
#include "pch.h"
#include <fstream>

class Player
{
public:
	/*Player();
	Player(const char name[30], int score);
	~Player();
	Player(char* Name, int score);
	void setName(const char name[30]);
	void setScore(const int score);*/

	void PlayerProfile();

	char* getName();
	int getScore();


	char playerName[30];
	int playerScore;

	void save(std::ofstream& out);
	bool load(std::ifstream& in);
};