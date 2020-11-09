// Preprocessor directive for compiler
// Directive it is a message to the compiler that instructs him to not include the following code if it has already included it
// Thus preventing the redefinition errors
#ifndef CALENDAR_H_INCLUDED
#define CALENDAR_H_INCLUDED

#include <iostream>
using namespace std;

class Calendar
{
public:
    // static variables are singular within a given class.
    // Objects do NOT have a separate copy of a variable.
    // All objects access a single variable.
    static int yearZero;
    char* myFavoriteMonth;
    char* myFavoriteDay;

    Calendar();
    ~Calendar();

    void setMyFavoriteMonth();

    // Automatic inline function (as implementation is in header file)
    char* getMyFavoriteMonth()
    {
        // Inline functions are concise, short and readable.
        return this->myFavoriteMonth;
    }

    // Explicit inline function (as set with the 'inline' keyword)
    inline void setMyFavoriteDay(char* day);
    inline void getMyFavoriteDay();

    // static functions are a common functionality that all object of a class should have and implement in the same way
    static void getCurrentTime();
};

// Explicitly declared 'inline' functions MUST have 'inline' keyword when writing implementation
// They MUST also be declared inside the header (.h) file
inline void Calendar::setMyFavoriteDay(char* day)
{
    this->myFavoriteDay = day;
}

inline void Calendar::getMyFavoriteDay()
{
    cout << "Your favorite day is: " << this->myFavoriteDay << endl;
}

#endif // CALENDAR_H_INCLUDED
