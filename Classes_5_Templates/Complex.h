#pragma once

class Complex
{
public:
	float real, img;

	Complex(float r, float i) : real(r), img(i) {}
	
	bool operator==(Complex& obj)
	{
		return this->real == obj.real && this->img == obj.img;
	}
};