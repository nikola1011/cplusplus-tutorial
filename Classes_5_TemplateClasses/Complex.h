#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	float real, img;

	Complex() : real(0), img(0) {}
	Complex(float r, float i) : real(r), img(i) {}
	~Complex() {}

	friend ostream& operator<<(ostream& output, const Complex& obj);
};

ostream& operator<<(ostream& output, const Complex& obj)
{
	return output << "Real: " << obj.real << " Imag: " << obj.img;
}