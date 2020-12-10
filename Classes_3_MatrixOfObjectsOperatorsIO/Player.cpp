#include "Player.h"

Player::Player()
{
}

Player::Player(int dressNumber, float pay)
{
	this->number = dressNumber;
	this->pay = pay;
}

// No need for destructor (all memory is static)
Player::~Player()
{
}

// No need for this operator overload (as all data within Player is primitive)
Player& Player::operator=(const Player& p)
{
	this->number = p.number;
	this->pay = p.pay;

	return *this;
}

bool Player::operator==(const Player& p)
{
	return this->number == p.number && this->pay == p.pay;
}

bool Player::operator!=(const Player& p)
{
	return !(*this == p);
}

bool Player::operator>(const Player& p)
{
	return this->pay > p.pay;
}

bool Player::operator>=(const Player& p)
{
	return this->pay >= p.pay;
}

bool Player::operator<(const Player& p)
{
	return !(this->pay >= p.pay);
}

bool Player::operator<=(const Player& p)
{
	return !(this->pay > p.pay);
}

ostream& operator<<(ostream& os, const Player& p)
{
	os << p.number << " " << p.pay << endl;
	return os;
}

istream& operator>>(istream& is, Player& p)
{
	is >> p.number >> p.pay;
	return is;
}