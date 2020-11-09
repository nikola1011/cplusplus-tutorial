#include <iostream>
#include "Calendar.h"
#include <ctime> // Header file that provides date and time functions

using namespace std;

// static variables MUST also be declared inside the .cpp file
int Calendar::yearZero;

Calendar::Calendar()
{
    cout << "Default constructor CALL" << endl;
}

Calendar::~Calendar()
{
    cout << "Destructor CALL" << endl;
    delete this->myFavoriteMonth;
}

// There is not 'static' keyword when implementing static functions
void Calendar::getCurrentTime()
{
    // 'this' pointer CANNOT be used in static methods as static methods do not "bind" to any object individually but are the same for all objects.
    // cout << this->myFavoriteMonth << endl; // COMPILER ERROR

    time_t now = time(0);
    cout << "Now is: " << ctime(&now) << endl;
}

void Calendar::setMyFavoriteMonth()
{
    cout << "Type in your favorite month:" << endl;
    delete this->myFavoriteMonth;
    this->myFavoriteMonth = new char[30];
    cin >> this->myFavoriteMonth;
}
