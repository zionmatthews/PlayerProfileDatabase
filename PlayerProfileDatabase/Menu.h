#pragma once
#include "pch.h"
#include "Player.h"

class Menu
{
public:
	/*Menu();
	~Menu();*/
	void start();


	void add(Player player);

	char playerName[30];
	int playerScore;


	int dataLength = 0;
	Player* playerData = new Player[dataLength];


	void save(std::ofstream& out);
	bool load(std::ifstream& in);

};
