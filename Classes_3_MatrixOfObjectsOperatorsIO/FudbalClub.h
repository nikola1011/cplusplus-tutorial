#pragma once
#include "Player.h"
#include <iostream>
using namespace std;

class FudbalClub
{
	int numOfPlayers;
	Player* players;

public:
	FudbalClub();
	FudbalClub(int numOfPlayers, Player players[]);
	FudbalClub(const FudbalClub& fc);

	~FudbalClub();

	FudbalClub& operator=(const FudbalClub& fc);
	/*FudbalClub& operator++();
	FudbalClub operator++(int n);*/

	friend ostream& operator<<(ostream& os, const FudbalClub& fc);
	friend istream& operator>>(istream& is, FudbalClub& fc);

	void sortPlayersByPay();
	void printPlayers();
};
