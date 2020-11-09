#include <iostream>
#include "Calendar.h"

// Header and source files - .h and .cpp files
//C++ classes (and often function prototypes) are normally split up into two files.
//The header file has the extension of .h and contains class definitions and functions.
//The implementation of the class goes into the .cpp file.
//By doing this, if your class implementation doesn’t change then it won’t need to be recompiled.
//Also it keep the code clean and readable.

using namespace std;

int main()
{
    // Initialize static variable (notice the class 'Calendar::', not object association)
    // Initialization must be done outside the class.
    Calendar::yearZero = 1970; // Unix time year
    cout << "Year zero is: " << Calendar::yearZero << endl;

    // Call static function
    Calendar::getCurrentTime();

    Calendar c; // Define object
    // Class objects can also access static variables
    cout << "Object year zero: " << c.yearZero << endl;
    // And static functions
    cout << "Current time through object call: " << endl;
    c.getCurrentTime();

    c.setMyFavoriteMonth();
    cout << "Your favorite month is: " << c.getMyFavoriteMonth() << endl;

    c.setMyFavoriteDay("Tuesday");
    c.getMyFavoriteDay();

    /// HOMEWORK
    // Write a class that has:
        // Header and Source file (.h and .cpp) file
        // Constructor, destructor (REMEMBER to delete/deallocate unused memory)
        // Two static variables (double and char*)
        // Two static methods
        // One implicit inline method
        // One explicit inline method
        // Implement a method to read from standard input (cin) and store data in variables and then show it on standard output (cout)
    
    return 0;
}

