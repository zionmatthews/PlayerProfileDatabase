#pragma once
#include "Player.h"
class DataBase
{
public:
	//Default constucters
	DataBase();
	~DataBase();

	//Adds new player profile
	void Add(Player newProfile);

	//Sorts list in alphabetical order
	void Sort();

	//LIst of player profiles
	void List();

	//Searches for profile
	void Search();

	//Saves player profiles
	void SavePlayerProfiles();

	//Loads player profiles
	bool load();

	Player getPlayer(int i);
	int getLength();


	

	//int BinarySearch(char * key);
	int BinarySearch(char  name[30]);



	//Array list of player
	Player* PlayerProfileList;

	int _arrayLength = 1;
	

};