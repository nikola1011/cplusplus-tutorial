#include "FudbalClub.h"

FudbalClub::FudbalClub() 
{
	this->numOfPlayers = 0;
	this->players = NULL;
}

FudbalClub::FudbalClub(int numOfPlayers, Player players[])
{
	this->numOfPlayers = numOfPlayers;
	this->players = new Player[this->numOfPlayers];

	for (int i = 0; i < this->numOfPlayers; i++)
		this->players[i] = players[i];
}

FudbalClub::FudbalClub(const FudbalClub& fc)
{
	this->numOfPlayers = fc.numOfPlayers;
	this->players = new Player[this->numOfPlayers];

	for (int i = 0; i < this->numOfPlayers; i++)
		this->players[i] = fc.players[i]; // Player class operator= overload call
}

FudbalClub::~FudbalClub()
{
	delete[] players;
}

FudbalClub& FudbalClub::operator=(const FudbalClub& fc)
{
	// Same object instance check
	if (this == &fc)
		return *this;

	if (this->numOfPlayers >= fc.numOfPlayers)
	{
		for (int i = 0; i < this->numOfPlayers; i++)
			this->players[i] = fc.players[i];
	}
	else
	{
		delete[] this->players;

		this->numOfPlayers = fc.numOfPlayers;

		this->players = new Player[this->numOfPlayers];
		for (int i = 0; i < this->numOfPlayers; i++)
			this->players[i] = fc.players[i];
	}

	return *this;
}

//FudbalClub& FudbalClub::operator++()
//{
//	for (int i = 0; i < this->currentScores; i++)
//		this->scores[i] += 1;
//
//	return *this;
//}
//
//FudbalClub FudbalClub::operator++(int n)
//{
//	FudbalClub temp = *this;
//	++(*this);
//	return temp;
//}

ostream& operator<<(ostream& os, const FudbalClub& fc)
{
	os << fc.numOfPlayers << endl;
	
	for (int i = 0; i < fc.numOfPlayers; i++)
		os << fc.players[i];
	
	return os;
}

istream& operator>>(istream& is, FudbalClub& fc)
{
	is >> fc.numOfPlayers;

	// Check for previous memory (deallocate, allocate new)
	delete [] fc.players;
	fc.players = new Player[fc.numOfPlayers];

	for (int i = 0; i < fc.numOfPlayers; i++)
		is >> fc.players[i];
	
	return is;
}

void FudbalClub::sortPlayersByPay()
{
	// Insertion sort

	for (int i = 0; i < this->numOfPlayers - 1; i++)
	{
		int index = i;

		for (int j = i + 1; j < this->numOfPlayers; j++)
		{
			if (this->players[index] < this->players[j])
			{
				index = j;
			}
		}

		if (index != i) // Do not swap the same elements
		{
			Player temp = this->players[i];
			this->players[i] = this->players[index];
			this->players[index] = temp;
		}
	}
}

void FudbalClub::printPlayers()
{
	cout << "FudbalClub players:" << endl;

	for (int i = 0; i < this->numOfPlayers; i++)
		cout << this->players[i];
}