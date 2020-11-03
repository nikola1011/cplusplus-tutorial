#include <iostream>

#define WORST_YEAR_EVER 2020
// #define MAX(a, b) if (a > b) cout << "BIGGER"; else cout << "SMALLER";

using namespace std;

int main()
{
	///
	/// Variables
	/// 

	// C++ language is a "case sensitive" language. myVariable is not the same as myVArIAbLE
	// A valid identifier is a sequence of one or more letters, digits, or underscore characters(_).
	// Spaces, punctuation marks, and symbols cannot be part of an identifier.
	// In addition, identifiers shall always begin with a letter.They can also begin with an underline character(_)

	// Declaring variables
	// <type_of_the_variable> <identifier-name_of_the_variable> [optional initialization];
	int validIdentfier; // at least 16b, at most 32b
	char myCharacter; // 1B in size (only a SINGLE character)

	// Assignment after initialization
	validIdentfier = 349;
	myCharacter = 'A';

	// Declaration with initialization
	int integerValue = validIdentfier;
	unsigned int onlyPositiveIntegers = 932;
	float decimalPoint = 943.2342f; // Suffix 'f' to notify compiler that you want float (if not, you will get a 'truncation' warning)
	double morePrecision = 4389.8923289223;
	bool isTheSwitchOn = true;

	// cout.precision(20); // Print floats and doubles with specifies precision
	cout << validIdentfier << " " << myCharacter << " " \
		<< integerValue << " " << onlyPositiveIntegers << " " \
		<< decimalPoint << " " << morePrecision << " " << isTheSwitchOn << " " << endl; // endl is from std namespace - prints a new line, or just use '\n'

	cout << "Hello World!\n";

	string myStringNoInit;
	myStringNoInit = "String variable assignement after declaration";
	string myString = "I am you new string, bla balb a...";
	cout << "START: " << myStringNoInit << " END\nSTART: " << myString << " END" << endl;
	// String concatenation (will output the same as with '<<' operator)
	// cout << "START: " + myStringNoInit + " END\nSTART: " + myString + " END" << endl;

	///
	/// Escape character \
    /// 
	/*
		\n	newline
		\r	carriage return
		\t	tab
		\v	vertical tab
		\b	backspace
		\f	form feed(page feed)
		\a	alert(beep)
		\'	single quote (')
		\"	double quote (")
		\ ? question mark(? )
		\\	backslash(\)
	*/
	cout << "\nNew line\n\tThis gets tabbed in. 2\bWhere is \'2\'? \aAlert!" << endl;

	///
	/// Constants
	/// 

	// Constanst are variable that are declared with 'const' and cannot be modified after initialization.
	// const int integerValue ; // COMPILER ERROR - 'const' variables MUST be initialized when declared
	// const int integerValue = 39; // COMPILER ERROR - 'redefinition' (the identifier already exists, see above)
	// Extension to color the console output: `VSColorOutput`
	const int myInt = 39;

	const bool areYouAlive = true;
	// areYouAlive = false; // COMPILER ERROR (you shouldn't kill a person :P) - but actually the 'const' declared variables are immutable

	const string multipleLines = "this is a string that gets \
set in multiple lines \
how is that possible  \
do you see it \
do you?";

	cout << "NOTICE NO NEW LINES: " << multipleLines;
	cout << endl;

	const int hexa = 0xff; // Notice the '0x' prefix
	cout << hexa << endl; // 'hexa' is printed as a decimal number (FF -> 255)

	const int octa = 012; // Notice the '0' prefix
	cout << octa << endl; // 'octa' is also printed as a decimal number - 12 -> 10 (2*8^0 + 1*8^1 = 10)


	///
	/// Preprocessor directives (use #define)
	///
	
	// Declare new constants in preprocessor directives with define keyword
	// Preprocessor with replace every occurence of the identifier in the directive with the value provided
	// Replacement happens at compiler time (before the program is even compiled).

	cout << WORST_YEAR_EVER << " is the worst year ever!" << endl;
	// MAX(10, 3);
}