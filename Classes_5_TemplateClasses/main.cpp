#include <iostream>
#include "Stack.h"
#include "Complex.h"

using namespace std;

int main()
{
    Stack<int> integers(5);
    integers.push(99);
    integers.push(111);
    integers.push(222);
    integers.pop();
    integers.pop();
    integers.push(555);
    cout << "All integers:\n" << integers << endl;

    Stack<Complex> complex(5);
    Complex c1(10, 10), c2(20, 20), c3(30, 30);
    complex.push(c1);
    complex.push(c2);
    complex.push(c3);
    complex.pop();
    cout << "All complex:\n" << complex << endl;
}