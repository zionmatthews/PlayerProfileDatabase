#pragma once
#include "Player.h"
class DataBase
{
public:
	DataBase();
	~DataBase();

	void Add(Player newProfile);

	void Sort();

	void Display();

	Player * Search(char* name);

	void SavePlayerProfiles();

	bool load();

	Player getPlayer(int i);
	int getLength();

	Player* PlayerProfileList;
	int _arrayLength;

};