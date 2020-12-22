#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	char* test;

	Complex(const char* t)
	{
		this->test = new char[strlen(t) + 1];
		strcpy_s(this->test, strlen(t) + 1, t);
	}
	~Complex()
	{
		delete[] this->test;
	}
};