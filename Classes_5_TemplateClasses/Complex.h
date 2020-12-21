#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	float real, img;

	Complex() : real(0), img(0) {}
	// Complex(Complex& obj) : real(obj.real), img(obj.img) {}
	Complex(float r, float i) : real(r), img(i) {}
	~Complex() {}

	// friend ostream& operator<< (ostream& out, Complex& c);
	friend ostream& operator<<(ostream& output, const Complex& obj);
	/*{
		return output << "Real: " << obj.real << " Imag: " << obj.img;
	}*/
};

ostream& operator<<(ostream& output, const Complex& obj)
{
	return output << "Real: " << obj.real << " Imag: " << obj.img;
}