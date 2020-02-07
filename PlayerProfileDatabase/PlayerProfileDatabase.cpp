// PlayerProfileDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "DataBase.h"
#include "Player.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	DataBase playerList;

	char input;
	playerList.load();

	while (1)
	{
		int choice;
		cout << "\n\n=============== PLAYER MODIFY MENU V3 ===================";
		cout << "\n1: Create a player profile.";
		cout << "\n2: show all player profiles created.";
		cout << "\n3: Search for a player profile.";
		cout << "\n4: Save and load the player profiles.";
		cout << "\n5: Exit from program.";

		cout << "\n\nEnter your choice...!\n";
		cin >> choice;
		system("cls");//clearing the console

		switch (choice)
		{
		case 1: //Create a player profile.

			cout << "\nGive the player profile a name..." << endl;
			char Name[30];
			cin >> Name;
			cout << "\nGive the player profile a score..." << endl;
			int Score;
			cin >> Score;
			playerList.Add(Player(Name, Score));
			break;
		case 2: //show all player profiles created.

			playerList.Display();
			system("pause");
			break;

		case 3: //Search for a player profile.

			/*system("cls");
			cout << "Who are you looking for?" << endl;
			cin >> Name;
			std::cout << playerList.Search(Name);
			break;*/

		case 4: //Save the player profiles.

			playerList.SavePlayerProfiles();
			playerList.load();
			break;

		case 5: //Exit from program.

			exit(0);
		}//end of switch

		if (choice == 3) {

		}

	}//end of the while loop

}//end of main