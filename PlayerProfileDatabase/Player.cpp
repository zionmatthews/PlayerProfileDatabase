#include "pch.h"
#include "Player.h"
#include <iostream>

void Player::PlayerProfile()
{
	std::cout << "Please enter a name for the profile: ";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> playerName;

	std::cout << "Please enter a score for the profile: ";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> playerScore;
}

void Player::Search()
{

}

//void Player::Remove() 
//{
//	std::cout << "Please select a profile to remove...";
//	std::cin.clear();
//	std::cin.ignore(std::cin.rdbuf()->in_avail());
//
//	Player* middleData = new Player[dataLength + 1];
//	for (int i = 0; i < dataLength; i++)
//	{
//		std::cout << i + 1 << ": " << playerData[i].getName() << playerData[i].getScore() << std::endl;		
//	}
//	std::cin.get();
//
//	for (int i = 0; i < dataLength; i++) 
//	{
//
//	}
//}

char* Player::getName()
{
	return playerName;
}

int Player::getScore()
{
	return playerScore;
}



//void Player::save(std::ofstream & out)
//{
//	if (!out.is_open())
//		return;
//	out.write(playerName, 30);
//	out.write((char*)&playerScore, sizeof(int));
//
//}
//bool Player::load(std::ifstream& in)
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
