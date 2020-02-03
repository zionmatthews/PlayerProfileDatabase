#include "pch.h"
#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::start() 
{
	while(1) 
	{
		int choice;
		cout << "\n\n=============== PLAYER MODIFY MENU V3 ===================";
		cout << "\n1: Create a player profile.";
		cout << "\n2: Remove a player profile.";
		cout << "\n3: Modify a player profile.";
		cout << "\n4: Save a player profile.";
		cout << "\n5: load a player profile.";
		cout << "\n6: Search for a player profile.";
		cout << "\n7: Exit from program.";
	
		cout << "\n\nEnter your choice...!\n";
		cin >> choice;
		system("cls");//clearing the console

		switch (choice) {

		case 7: exit(0); //closes the program		

		default: cout << "Wrong Input, please try again...\n";
			break;
		}
	}
}