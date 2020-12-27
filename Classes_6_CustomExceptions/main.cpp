#include <iostream>
#include "CustomException.h"

using namespace std;

int main()
{
	int myArray[] = { 1, 2, 3 };

	try
	{
		int index = 0;
		
		cout << "Enter index to access the array:" << endl;
		cin >> index;

		if (index < 0)
		{
			throw CustomException("Index cannot be negative", index);
		} 
		// NOTE: No handling for greater than bounds situation

		cout << "The element with the requested index is: " << myArray[index] << endl;
	}
	catch (CustomException& e) // Handle situations where index is negative
	{
		cout << "Custom exception: " << endl;
		e.explain();
	}
	catch (exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Generic exception occured." << endl;
	}
}