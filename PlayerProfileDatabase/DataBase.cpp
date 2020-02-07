#include "pch.h"
#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <string>

//defualt construter
DataBase::DataBase()
{
	_arrayLength = 0;
}

//defualt construter
DataBase::~DataBase()
{

}

//Adds the player profile to the array list
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
	Sort();
}//end of DataBase Add


//Sorts the list in alhpabetical order
void DataBase::Sort()
{
	bool sorted = false;

	while (!sorted)
	{
		int swaps = 0;
		//loop
		for (int i = 0; i < _arrayLength - 1; i++)
		{
			int p = i + 1;

			//loop for the names
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
		
		if (swaps <= 0)
		{
			sorted = true;
		}
	}//end of while
	
}//end of Databass Sort

//Shows the list of all created player profiles that are stored in the array
void DataBase::List()
{	
	system("cls");
	std::cout << _arrayLength << std::endl;
	//print out names and  scores
	for (int i = 0; i < _arrayLength; i++)
	{
		std::cout << PlayerProfileList[i].getName() << ": " << PlayerProfileList[i].getScore() << std::endl;
	}

	if (_arrayLength <= 0)
	{
		std::cout << "\nNo profiles found. " << std::endl;
	}
}//End of Database Display

//searches for an inputted profile and allows the user to edit it
void DataBase::Search()
{
	char input[30] = "\0";
	int inputint = 0;
	int index = 0;

	std::cout << "Enter the name of the player to search for." << std::endl;

	//Clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> input;
	index = BinarySearch(input);
	if (index != -1) {

		std::cout << PlayerProfileList[index]._Name << PlayerProfileList[index]._Score << std::endl;

		std::cout << "Do you want to edit this profile (yes/no)" << std::endl;
		std::cin.clear();
		std::cin >> input;
		if (strcmp(input, "yes") == 0)
		{
			std::cout << "Choose a new name for this profile " << std::endl;
			std::cout << "New name:" << std::endl;;
			std::cin >> input;
			PlayerProfileList[index].setName(input);
			std::cout << "Choose a new score For this profile" << std::endl;
			std::cout << "New score:";
			std::cin >> inputint;
			PlayerProfileList[index].setScore(inputint);
			return;
		}
		else if (strcmp(input, "no") == 0)
		{
			return;
		}
		else
		{
			system("CLS");
			std::cout << "Invalid input" << std::endl;
		}
	}
	else
	{
		system("CLS");
		std::cout << "Player not found." << std::endl;
	}
}
//grabs  variable out of the Array of players
Player DataBase::getPlayer(int i)
{
	return PlayerProfileList[i];
}//end of DataBase get player

int DataBase::getLength()
{
	return _arrayLength;
}//end of DataBase get length

//saves profile names and scores to the save file
void DataBase::SavePlayerProfiles()
{
	std::ofstream file;
	file.open("PlayersRecord.dat", std::ios::out);

	//saves arraylength variable
	file << _arrayLength << std::endl;

	//saves player and high scores
	for (int i = 0; i < _arrayLength; i++)
	{
		file.write(PlayerProfileList[i].getName(), 30);
		
	}

	file.close();
}//end of DataBase Save

//loads the profile  from the save file
bool DataBase::load()
{

	char* name = new char[30];
	int tempScore;
	int tempArrayLength;

	std::ifstream file;

	file.open("PlayersRecord.dat", std::ios::in);

	//checks if the file is open
	if (!file.is_open())
		return false;

	//loads in the array  from the file
	file >> tempArrayLength;

	//loads in name and score
	for (int i = 0; i < tempArrayLength; i++)
	{
		file >> name;
		file >> tempScore;
		
		Player newProfile(name, tempScore);
		Add(newProfile);
	}

	//checks the file
	if (file.rdstate())
		return false;

	return true;
}//end of DataBase load



//searches the database for the inputted player by name
int DataBase::BinarySearch(char  name[30])
{
	int max = _arrayLength - 1;
	int min = 0;


	while (min != max)
	{
		int middle = (min + max) / 2;
		if (strcmp(PlayerProfileList[middle].getName(), name) == 0)
		{
			return middle;
		}
		else if (strcmp(PlayerProfileList[middle].getName(), name) < 0)
		{
			min = middle + 1;

		}
		else if (strcmp(PlayerProfileList[middle].getName(), name) > 0)
		{
			max = middle - 1;
		}
	}
	return -1;
}