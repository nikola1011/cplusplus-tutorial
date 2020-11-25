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

// The parameter expected for a member function overload for operations such as operator+ is naturally the operand to the right hand side of the operator (common for all binary operators)
// See the parameters and operators table below to understand how to declare parameters for overloading operator functions
//
//  NOTE: Replace '@' with the operand. `a` is an object of class A, `b` is an object of class B and `c` is an object of class C. `TYPE` is just any type.
//
//	@a + -*&!~++ --A::operator@()	operator@(A)
//	a@	++ --A::operator@(int)	operator@(A, int)
//	a@b + -*/ % ^&| < > == != <= >= << >> && || , A::operator@(B)	operator@(A, B)
//	a@b = += -= *= /= %= ^= &= |= <<= >>= []	A::operator@(B)-
//	a(b, c...)	()	A::operator()(B, C...) -
//	a->b->A::operator->() -
//	(TYPE)a	TYPE	A::operator TYPE() -

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

	int getSerialNumber() // Reminder: inline function (whole class is inline)
	{
		return serialNumber;
	}

	// <return_type> operator<operator_sign>(<parameter1>, ... <parameter_N>) { ... }
	// Whenever you compare two cars with '==', this method will be called
	bool operator==(Car& car)
	{
		// leftOperand == rightOperand
		// `this` is leftOperand
		// `car` parameter is rightOperand
		if (this->serialNumber == car.serialNumber)
			return true;
		else
			return false;

		// Shorter version to write previous code
		// return this->getSerialNumber() == car.getSerialNumber();
	}

	// Member function operator overload
	Car operator+(const Car& car)
	{
		Car temp(this->serialNumber);
		temp.velocity = this->velocity + car.velocity;
		return temp;
	}

	// Non member function operator overload
	friend Car operator-(const Car& car1, const Car& car2);
	
	Car& operator=(const Car& car)
	{
		this->serialNumber = car.serialNumber;
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

// Non member function operator overload (must be declared friend)
Car operator-(const Car& car1, const Car& car2)
{
	Car temp(car1.serialNumber);
	temp.velocity = car1.velocity - car2.velocity;
	return temp;
}

// You can also declare overload operators outside the class -> NON member class operator overloading.
// But you no longer have access to `this` as you are no longer inside the class definition
// Therefore you need to add another class parameter
//Car& operator+(Car& leftOperand, Car& rightOperand)
//{
//	leftOperand.velocity += rightOperand.velocity;
//	return leftOperand;
//}

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

	Car resultCar(0);
	resultCar = c1 + c2;
	cout << "Add cars together: " << resultCar.velocity << endl;

	resultCar = c1 - c2;
	cout << "Substract cars: " << resultCar.velocity << endl;

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