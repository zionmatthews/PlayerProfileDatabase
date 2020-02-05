#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Menu::start()
{
	while (1)
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
				
		if (choice == 1) {
			Player player;
			player.PlayerProfile();
			add(player);
		}
		if (choice == 2) {
			/*Player player;
			player.Remove();
			Remove(player);*/
		}
		if (choice == 6) {
			Player player;
			player.Search();
			Search(player);
		}
		if (choice == 7) {
			exit(0);
		}

	}
}

void Menu::add(Player player)
{
	cout << "Player Profile Added";
	Player* middleData = new Player[dataLength + 1];

	for (int i = 0; i < dataLength; i++)
	{
		middleData[i] = playerData[i];
	}
	playerData = middleData;
	playerData[dataLength] = player;
	dataLength++;
}

void Menu::Remove(Player player)
{
	cout << "Player Profile Removed";
	Player* middleData = new Player[dataLength - 1];

	for (int i = 0; i < dataLength; i++)
	{
		middleData[i] = playerData[i];
	}
	playerData = middleData;
	playerData[dataLength] = player;
	dataLength++;
}

void Menu::Search(Player player) 
{
	std::cout << "The list of all created player profiles" << ::endl;
	Player* middleData = new Player[dataLength + 1];
	for (int i = 0; i < dataLength; i++) 
	{
		std::cout << i + 1 << ": " << playerData[i].getName() << "  " << playerData[i].getScore() << std::endl;
	}
	playerData = middleData;
	playerData[dataLength] = player;
	dataLength++;
}

//void Menu::save(std::ofstream & out)
//{
//	if (!out.is_open())
//		return;
//	out.write(playerName, 30);
//	out.write((char*)&playerScore, sizeof(int));
//
//}
//bool Menu::load(std::ifstream& in)
//{
//	if (!in.is_open())return false;
//
//	//Load name
//	in.read(playerName, 30);
//
//	if (in.rdstate()) return false;
//	//Load Score
//	in.read((char*)&playerScore, sizeof(int));
//
//	if (in.rdstate()) return false;
//
//
//	return true;
//}

//void Container::save()
//{
//	std::ofstream ofs("test.txt", std::ofstream::out, std::ofstream::trunc);
//
//	ofs << dataLength << std::endl;
//	for (int i = 0; i < dataLength; i++)
//	{
//		ofs << playerData[i].getName() << std::endl;
//		ofs << playerData[i].getScore() << std::endl;
//	}
//
//	ofs.close();
//}
//
//bool Container::load()
//{
//	std::ifstream ifs("test.txt", std::ifstream::in);
//
//
//	ifs >> dataLength;
//	for (int i = 0; i < dataLength; i++)
//	{
//
//	}
//
//	return ifs.operator bool();
//
//	ifs.close();
//}