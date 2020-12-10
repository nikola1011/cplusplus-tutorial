#pragma once
#include <iostream>
using namespace std;

class Player
{
	int number;
	float pay;

public:
	Player();
	Player(int dressNumber, float pay);
	~Player();

	Player& operator=(const Player& p);

	bool operator==(const Player& p);
	bool operator!=(const Player& p);
	bool operator>(const Player& p);
	bool operator>=(const Player& p);
	bool operator<(const Player& p);
	bool operator<=(const Player& p);

	friend ostream& operator<<(ostream& os, const Player& p);
	friend istream& operator>>(istream& is, Player& p);
};