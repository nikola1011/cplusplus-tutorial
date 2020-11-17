#include <iostream>

using namespace std;

// Classes, essentially, define new types to be used in C++ code. 
// Classes should interact with operators (*, +, %, ==, !, ...) as other primitive types (int, float) can.
// This can be done by operator overloading.

// NOTES:
// Operators ::  .  .*  ?: CANNOT be overloaded
// New operators CANNOT be created
// Precedence, grouping or number of operator operands cannot be changed
// && and || lose short circut evaluation

class Car
{
	int serialNumber;
	const static int MAX_SERVICE_YEARS = 10;
	float serviceYears[MAX_SERVICE_YEARS];

public:
	float velocity = 0;

	Car(int serialNumber) 
	{ 
		this->serialNumber = serialNumber;
		this->serviceYears[0] = 0.5f;
		this->serviceYears[1] = 1.2f;
		this->serviceYears[2] = 2.5f;
		this->serviceYears[3] = 2.5f;
		this->serviceYears[4] = 5.0f;
	}

	int getSerialNumber() // inline function (whole class is inline)
	{
		return serialNumber;
	}

	// <return_type> operator<operator_sign>(<parameter1>, ... <parameter_N>) { ... }
	// Whenever you compare two cars with '==', this method will be called
	bool operator==(Car& car)
	{
		if (this->getSerialNumber() == car.getSerialNumber())
			return true;
		else
			return false;

		// Shorter version to write previous code
		// return this->getSerialNumber() == car.getSerialNumber();
	}

	Car& operator+(Car& car)
	{
		this->velocity += car.velocity;
		return *this;
	}

	Car& operator=(Car& car)
	{
		this->serialNumber = car.getSerialNumber();
		this->velocity = car.velocity;
		return *this;
	}

	float operator[](int i)
	{
		if (i < MAX_SERVICE_YEARS)
		{
			return this->serviceYears[i];
		}
		else
		{
			return -1;
		}
	}

};

int main()
{
	int SERIAL_NUMBER_1 = 11111111;
	int SERIAL_NUMBER_2 = 1058239239; // Is this a valid value for int ?
	
	Car c1(SERIAL_NUMBER_1);
	Car c2(SERIAL_NUMBER_2);

	cout << "c1 and c2 are the same: " << (c1 == c2) << endl; // NOTE: Parentheses ARE needed because of operator precedence
	cout << "c1 and c2 are the same: " << c1.operator==(c2) << endl; // This is the same as previous line

	//  The operator overloads are just regular functions which can have any behavior
	c1.velocity = 40;
	c2.velocity = 10;
	cout << "Add cars together: " << (c1 + c2).velocity << endl;

	Car c3(0);
	
	cout << "c3 serialNumber: " << c3.getSerialNumber() << endl;
	c3 = c1;
	cout << "c3 serialNumber: " << c3.getSerialNumber() << endl;

	const int serviceYear = 3;
	cout << serviceYear << " service year " << c1[serviceYear - 1] << endl;


	/// HOMEWORK
		// Create `Complex` class.
		// Has two private float fields: real, img
		// Implement the following operators for `Complex` class:
			// =, ==, !=, +, +=, -, -=
}