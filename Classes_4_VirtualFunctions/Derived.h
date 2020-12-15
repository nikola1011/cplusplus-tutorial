#pragma once

#include "Base.h"

class Derived : public Base
{
public:
	/*int nonVirtualFunc()
	{
		cout << "DERIVED - Non virtual function call." << endl;
		return 0;
	}*/
	virtual int virtualFunc()
	{
		cout << "DERIVED - Virtual function call." << endl;
		return 0;
	}

	int callBaseFunctionTest() 
	{
		Base::nonVirtualFunc();
		// nonVirtualFunc();
		return 0;
	}

	~Derived()
	{
		cout << "DERIVED - Destructor call." << endl;
	}
};