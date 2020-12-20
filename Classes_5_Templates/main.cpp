#include <iostream>

using namespace std;

// template <template_parameteres...> <function_description>
template <class T>
T sum(T a, T b)
{
    T result; // T used inside a function to declare the given type
    result = a + b;
    return result; // T can also be the return type
}

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

    cout << "Fixed multiply (non type arguments): " << fixedMultiply<int, 2>(10) << endl;
    cout << "Fixed multiply (non type arguments): " << fixedMultiply<int, 3>(10) << endl;
}