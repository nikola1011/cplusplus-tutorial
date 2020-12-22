#include <iostream>
#include "Complex.h"
#include "Decimal.h"

using namespace std;

// template <template_parameteres...> <function_description>
template <class T>
T sum(T a, T b)
{
    T result; // T used inside a function to declare the given type
    result = a + b;
    return result; // T can also be the return type
}

// When previous template function is called for `int` instead of `T`,
// the compiler will generate the following code:
// int sum(int a, int b)
// {
//     int result;
//     result = a + b;
//     return result;
// }

template <class T, class U> // Use multiple parameters
bool areEqual(T a, U b)
{
    return (a == b);
}

// Non type arguments
template <class T, int N>
T fixedMultiply(T value)
{
    return value * N;
}

int main()
{
    // Invoking a template function
    // func_name <template_arguments...> ([func_arguments])
    cout << "Int result is: " << sum<int>(10, 20) << endl;
    
    cout << "Float result is: " << sum<float>(10.01f, 20.2f) << endl;
    cout << "Double result is: " << sum<double>(10.0001, 20.222222f) << endl;

    cout << "Char result: " << sum<char>('a', 'b') << endl; // Can you add two characters ??

    // Implicit argument conversion when calling the template function
    cout << "Float result (implicit conversion): " << sum(239.0f, 161.2f) << endl;

    int x = 10;
    float y = 10.0;

    // Call template with different types as arguments + implicit argument conversion
    if (areEqual(10, 10.0))
        cout << "x and y are equal" << endl;
    else
        cout << "x and y are not equal" << endl;

    Complex c1(11.1f, 33.3f), c2(11.1f, 33.3f);
    cout << "Are complex numbers equal: " << areEqual(c1, c2) << endl;
    // Next line is equivalent to previous one
    cout << "Are complex numbers equal: " << areEqual<Complex>(c1, c2) << endl;

    Decimal d1(11.1f), d2(22.222f);
    cout << "Are decimal numbers equal: " << areEqual(d1, d2) << endl;
    // Next line is equivalent to previous one
    cout << "Are decimal numbers equal: " << areEqual<Decimal>(d1, d2) << endl;

    // Compile error if appropriate operator overload to compare Decimal to Complex does not exist
    // cout << "Is decimal equal to complex: " << areEqual<Decimal, Complex>(d1, c1) << endl;

    cout << "Fixed multiply (non type arguments): " << fixedMultiply<int, 2>(10) << endl;
    cout << "Fixed multiply (non type arguments): " << fixedMultiply<int, 3>(10) << endl;
}