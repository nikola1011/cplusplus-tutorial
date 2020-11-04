#include <iostream>

using namespace std;

// For a C++ program, the memory of a computer is like a succession of memory cells, each one byte in size, and each with a unique address.
// This way, each cell can be easily located in the memory by means of its unique address (a pointer).
// When a variable is declared, the memory needed to store its value is assigned a specific location in memory (its memory address). 
// C++ program is able to obtain the address of a variable during runtime in order to access data cells that are at a certain position relative to it.

// Read more detailed explanations about pointers on -> http://www.cplusplus.com/doc/tutorial/pointers/

int main()
{
    // & - 'address of' operator
    // * - 'dereference' operator (value of the memory address that is pointed to)

    int x = 20;
    // A variable which stores the address of another variable is called a pointer.
    // Declared as <type> *<pointer_identifier_name>;
    int* pointerToX;
    pointerToX = &x; // Give pointer an address of the 'x' variable. (some address in memory, known at runtime).

    cout << "Pointer address: " << pointerToX << " Pointer address value: " << *pointerToX << endl;
    cout << "pointerToX == &x -> " << (pointerToX == &x) << "\n*pointerToX == x -> " << (*pointerToX == x) << endl;

    // When you change the dereferenced value of the pointer, you change the actual data in memory that pointer points to.
    *pointerToX = 83;
    cout << "x is now: " << x << endl;

    // Each pointer is intended to point to a different data type, but, in fact, 
    // all of them are pointers and all of them are likely going to occupy the same amount of space in memory
    // (the size in memory of a pointer depends on the platform where the program runs).
    int* i; // [pointer] -> (data - [4B][4B]...[4B])
    char* c; // [pointer] -> (data - [1B][1B]...[1B])
    double* d; // [pointer] -> (data - [8B][8B]...[8B])
    cout << "int: " << sizeof(int) << " char: " << sizeof(char) << " double: " << sizeof(double) << endl;
    cout << "int*: " << sizeof(i) << " char*: " << sizeof(c) << " double*: " << sizeof(d) << endl;

    // Declaring multiple pointers to the same data type
    int* p1, * p2, * p3;
    int* p4, p5, p6; // !!!p5 and p6 are not pointers, but regular INT variables


    // TODO: Pointers and arrays -> http://www.cplusplus.com/doc/tutorial/pointers/
}