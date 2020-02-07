#pragma once
#include <string>
class Player
{
public:
	Player();
	~Player();

	Player(char* name, int score);

	char* getName();
	int getScore();
	void editPlayerName(char* name);

	void setName(const char name[30]);
	void setScore(const int score);

	char Name[30];
	int Score;
};