#pragma once
#include <iostream>
#include <exception>

// using namespace std;

class CustomException : public std::exception
{
	int index;
public:
	CustomException(const char* e, int i) : std::exception(e), index(i) {}

	void explain()
	{
		std::cout << "CustomException details:\n\t" <<
			"Exception details:\n\t" << what() /* function inherited from base class */ << "\n\t"
			"Index:\n\t" << this->index << std::endl;
	}

	// Predefine the inherited virtual function
	//virtual const char* what() const throw()
	//{
	//	std::string* ret = new std::string("Additional information: blabla\nBase exception:\n\t" + std::string(exception::what()));
	//	return ret->c_str(); // convert ret to `const char*` and return
	//}
};
