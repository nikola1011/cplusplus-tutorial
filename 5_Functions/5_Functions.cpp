#include <iostream>
#include <string>

using namespace std;

// This is a region (way of grouping things together to make them visible/invisible)
#pragma region Basic functions

/// Explain function call on stack
/// Function declaration
// <return_type> <identifier-name_of_the_function> (<param1_type> <param1_identifier, ... <paramN_type> <paramN_identifier) 
// { 
//     function body
// }

int addNumbers(int a, int b)
{
    return a + b;
}

string concatenateStrings(string s, string q)
{
    return s + q;
}

void printNumber(string s, int x)
{
    cout << s << " " << x << endl;
    // 'void' functions have no return value
}

void callMe()
{
    // You can declare a function and never call it.
    // If a function is never called, its' never executed, but can exist.
}
#pragma endregion

#pragma region Argument Value/Reference pass
// Value pass -> Copy argument value into the function
// Reference pass -> Pass memory location(reference) of an argument (do NOT make a copy)

void valuePass(int x)
{
    printNumber("Value inside the function: ", x);
    // Value pass argument changes are not reflected outside of the function
    x = 10;
    printNumber("Value inside the function changed: ", x);
}


void referencePass(int& y) // References are declared with &
{
    printNumber("Value inside the function: ", y);
    // Reference pass argument changes can be seen outside the function
    y = 10;
    printNumber("Value inside the function changed: ", y);
}

// See the previous 'concatenateStrings' method which is inefficient as string arguments are copies (pass by value)
// For bigger strings this function will execute faster than the 'concatenateStrings' which is a value pass one.
string concatenateStringsByReference(string& s, string& q)
{
    return s + q;
}

void printMyNameAndAge(const string& name, const int age/*, int otherParameters*/)
{
    cout << "I am: " << name << " " << age << endl;
    // age = 903; // COMPILER ERROR (parameter is not modifiable)
    // 'const' is an indication that the function should not try to change the value of the parameter(s) passed in, and this is forced by compiler
}
#pragma endregion

#pragma region Inline functions
// Inline functions are ways of copying complete functions bodies to the place where the actual function calls takes place
// Thus avoiding the need for call/argument push to the Stack (providing faster execution)
// 'inline' keyword informs the compiler that this function SHOULD be inlined at every call and that this method is preferred over the usual call mechanism (through Stack).
// 'inline' tells the compiller the preferred method BUT it does not force it to do so. Compiller may decide not to inline the function.
// Most compilers already do this function inlining automatically.
// 'inline' is mostly used for short functions that are not expensive to compute
inline int getAbsoluteValue(int x)
{
    if (x < 0)
    {
        return x * -1;
    }
    else
    {
        return x;
    }
    //// or
    //if (x < 0)
    //    return x * -1;
    //else
    //    return x;
    //// or
    //if (x < 0)
    //    return x * -1;
    //return x;
    //// or
    //return x < 0 ? x * -1; x;
}
#pragma endregion

#pragma region Default value parameters
// Parameters can have default values thus making parameters optional when calling the function.
// Default value parameters are, by order, last.
int cutInSlices(int pizza, int slices = 6)
{
    return pizza / slices;
}

#pragma endregion

#pragma region Recursivity (a complete mindfuck)
// Can recursive functions be inline ?
// They can, but 'inline' is just a hint to compiler to make a function inline. It could make it inline, it could just bypass it, or copy the function a limited number of times (unroll recursion to a certain extent).
/*inline*/ int sumFirstN(int n)
{
    if (n == 0)
        return 0;

    return n + sumFirstN(n - 1);

    // Write it shorter (one line)
    // return n ? n + sumFirstN(n - 1) : 0;
}

string printTabs(int timesToPrint = 4)
{
    if (timesToPrint == 0)
        return "";
    
    return string(timesToPrint, '\t') + to_string(timesToPrint) + "\n" + printTabs(--timesToPrint);
}

#pragma endregion

#pragma region Prototype func declaration
// In C++, identifiers can only be used in expressions once they have been declared.
// For example, some variable x cannot be used before being declared with a statement, such as: int x;
// Same applies to functions.
// Functions cannot be called before they are declared (that's why all the previous functions are before main function, from which they are called) 

float funcPrototype(float); // Declaration only
void funcPrototypeDefaultParams(int x, string s = "bla"); // Declaration only

#pragma endregion

int main() // Program execution STARTS here
{
    /// Function call
    // <function_name>(<argument1>, ... <argumentN>);

    const int num1 = 2;
    int result = addNumbers(num1, 90);
    printNumber("Result is: ", result);

    addNumbers(3490, 1); // What will happen with the result ?

    cout << concatenateStrings("mystring1", " My STRING 2");


    /// Value/Reference argument pass
    cout << endl;
    // Value pass
    cout << "VALUE PASS:\n";
    int num2 = 4390;
    printNumber("Value before function call: ", num2);
    valuePass(num2); // Argument 'num2' is used to initialize the 'x' parameter in function call
    printNumber("Value after function call: ", num2);

    // Reference pass
    cout << "REFERENCE PASS:\n";
    printNumber("Value before function call: ", num2);
    referencePass(num2); // Argument 'num2' is used to initialize the 'y' parameter in function call
    printNumber("Value after function call: ", num2);

    string s = "blabkas", q = "naother alkdsfjlaksjdfieasdf";
    cout << concatenateStringsByReference(s, q) << endl;

    cout << "INLINE FUNCTION CALL:" << endl;
    cout << "abs -> " << getAbsoluteValue(9340) << endl;
    cout << "abs -> " << getAbsoluteValue(-40) << endl;
    cout << "abs -> " << getAbsoluteValue(0) << endl;

    cout << "DEFAULT PARAMETER VALUES:" << endl;
    cout << cutInSlices(892, 2) << endl;
    cout << cutInSlices(892) << endl;

    cout << "RECURSIVE FUNCTIONS:" << endl;
    cout << sumFirstN(5) << endl;
    cout << printTabs() << endl;

    cout << "FUNCTION PROTOTYPES:" << endl;
    // declaredWithBodyAfterMain(); // COMPILER ERROR - identifier not found
    float returnValue = funcPrototype(1.393f);
    cout << "funPrototype returned: " << returnValue << endl; // Can this be written shorter ?
    funcPrototypeDefaultParams(3);

    // 'main' function has an implicit 'return 0;' statement by compiler (if it ends successfully - meaning without encountering errors)
} // Program execution ENDS here

#pragma region Prototype func implementation
void declaredWithBodyAfterMain()
{

}

float funcPrototype(float p)
{
    p *= 2;
    cout << "funPrototype running, p*2 = " << p << endl;
    return p;
}

void funcPrototypeDefaultParams(int x, string s)
{
    cout << "funcPrototypeDefaultParams running, x = " << x << " s = " << s << endl;
}
#pragma endregion