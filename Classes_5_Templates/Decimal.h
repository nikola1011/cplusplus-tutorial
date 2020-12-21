#pragma once

class Decimal
{
public:
	float number;

	Decimal(float n) : number(n) {}

	bool operator==(Decimal& obj)
	{
		return this->number == obj.number;
	}

	/*bool operator==(Complex& obj)
	{
		return this->number == obj.real;
	}*/
};