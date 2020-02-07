#include "pch.h"
#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <string>


DataBase::DataBase()
{
	_arrayLength = 0;
}


DataBase::~DataBase()
{

}

//Adds another player to the list of players
void DataBase::Add(Player newProfile)
{
	Player* newList = new Player[_arrayLength + 1];

	for (int i = 0; i < _arrayLength; i++)
	{
		newList[i] = PlayerProfileList[i];
	}

	newList[_arrayLength] = newProfile;

	_arrayLength++;

	PlayerProfileList = newList;
}


//Sorts the playerlist by alphabetical order
void DataBase::Sort()
{
	bool sorted = false;

	while (!sorted)
	{
		int swaps = 0;
		//loop counting through the list of players
		for (int i = 0; i < _arrayLength - 1; i++)
		{
			int p = i + 1;

			//loop counting through the letters in names of players and comparing
			for (int n = 0; n < 30; n++)
			{
				if (PlayerProfileList[i].getName()[n] > PlayerProfileList[p].getName()[n])
				{
					Player tempPlayer = PlayerProfileList[p];
					PlayerProfileList[p] = PlayerProfileList[i];
					PlayerProfileList[i] = tempPlayer;
					swaps++;
					break;
				}
				else if (PlayerProfileList[i].getName()[n] == PlayerProfileList[p].getName()[n])
				{

				}
				else
				{
					break;
				}
			}
		}
		//if swaps is greater than 0 the function should continue the loop until no swaps happen
		if (swaps <= 0)
		{
			sorted = true;
		}
	}
	//savePlayers();
}

//Displays the list of players and their scores to the console
void DataBase::Display()
{
	Sort();
	system("cls");

	//print out players and high scores
	for (int i = 0; i < _arrayLength; i++)
	{
		std::cout << PlayerProfileList[i].getName() << ": " << PlayerProfileList[i].getScore() << std::endl;
	}

	if (_arrayLength <= 0)
	{
		std::cout << "\nNo profiles found. " << std::endl;
	}
}

//Finds a specific player in the list by high score or name
Player * DataBase::Search(char* name)
{
	int i = 0;
	int max = _arrayLength - 1;


	while (i <= max)
	{
		int searchSpot = (i + max) / 2;
		if (PlayerProfileList[searchSpot].getName() == name)
		{
			return &PlayerProfileList[searchSpot];
		}
		else if (PlayerProfileList[searchSpot].getName() < name)
		{
			i = searchSpot + 1;
		}
		else if (PlayerProfileList[searchSpot].getName() > name)
		{
			i = _arrayLength - 1;
		}
	}
	return nullptr;
}

//saves player names and high scores to the save file
void DataBase::SavePlayerProfiles()
{
	std::ofstream file;
	file.open("PlayersRecord.dat", std::ios::out);

	//saves arraylength variable
	file << _arrayLength << std::endl;

	//saves player and high scores
	for (int i = 0; i < _arrayLength; i++)
	{
		file << getPlayer(i).getName() << std::endl;
		file << getPlayer(i).getScore() << std::endl;
	}

	file.close();
}

//loads players from the save file
bool DataBase::load()
{

	char* name = new char[30];
	int temphighscore;
	int tempArrayLength;

	std::ifstream file;

	file.open("PlayersRecord.dat", std::ios::in);

	//checks if file is open
	if (!file.is_open())
		return false;

	//loads in the array length from the file
	//file.read((char*)&_arrayLength, sizeof(int));
	file >> tempArrayLength;

	//loads in player and player score
	for (int i = 0; i < tempArrayLength; i++)
	{
		file >> name;
		file >> temphighscore;

		//creates player and adds player with loaded name to the list
		Player newProfile(name, temphighscore);
		Add(newProfile);
	}

	//checks to see if loads correctly
	if (file.rdstate())
		return false;

	return true;
}

//grabs the player variable out of the Array of players
Player DataBase::getPlayer(int i)
{
	return PlayerProfileList[i];
}

int DataBase::getLength()
{
	return _arrayLength;
}

