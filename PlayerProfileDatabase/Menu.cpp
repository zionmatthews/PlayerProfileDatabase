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
		cout << "\n2: Modify a player profile.";
		cout << "\n3: Save a player profile.";
		cout << "\n4: load a player profile.";
		cout << "\n5: Search for a player profile.";
		cout << "\n6: Exit from program";
	
		cout << "\n\nEnter your choice...!\n";
		cin >> choice;
		system("cls");//clearing the console

		switch (choice) {


		}
	}
}