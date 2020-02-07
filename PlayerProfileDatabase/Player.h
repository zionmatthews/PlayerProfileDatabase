#pragma once
#include <string>
class Player
{
public:
	//Defualt constructers
	Player();
	~Player();

	//Name and score for int
	Player(const char name[30], int score);

	//Grabs Name and Score
	char* getName();
	int getScore();
	//Edit profile name
	//void EditProfileName(char* name);

	//Sets name and score
	void setName(const char name[30]);
	void setScore( int score);

	//Char array
	char _Name[30];
	//Score
	int _Score;

	//To save and load
	void save(std::ofstream& out);
	bool load(std::ifstream& in);
};
