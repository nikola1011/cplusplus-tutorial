#pragma once

#include <iostream>

using namespace std;

class Base
{
	void onlyInBase()
	{
		cout << "BASE - Only in base function call" << endl;
	}

public:
	int nonVirtualFunc()
	{
		cout << "BASE - Non virtual function call." << endl;
		return 0;
	}
	
	virtual int virtualFunc()
	{
		cout << "BASE - Virtual function call." << endl;
		return 0;
	}

	virtual ~Base()
	{
		cout << "BASE - Destructor call." << endl;
	}
};