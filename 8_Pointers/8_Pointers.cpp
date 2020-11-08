#include <iostream>

using namespace std;

// For a C++ program, the memory of a computer is like a succession of memory cells, each one byte in size, and each with a unique address.
// This way, each cell can be easily located in the memory by means of its unique address (a pointer).
// When a variable is declared, the memory needed to store its value is assigned a specific location in memory (its memory address).
// C++ program is able to obtain the address of a variable during runtime in order to access data cells that are at a certain position relative to it.

// Read more detailed explanations about pointers on -> http://www.cplusplus.com/doc/tutorial/pointers/

#pragma region Helper functions declarations
void printArray(int a[], int len);
void printArrayByPtr(const float* arrayPointer, int arrayLength);
void increment_by(int* startPointer, int* endPointer, int incrStep = 2);
//void increment_by(const int* startPointer, const int* endPointer, int incrStep = 2);
void replaceBy(char * characterSequence, char replaceChar, char toReplaceBy);
double* findMe(double doubleArray[], int length, double elementToFind);
#pragma endregion

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


    /// Pointers and arrays

    const int ARRAY_LEN = 5;
    int basicArray[] = { 11, 22, 33, 44, 55 };
    int* pointerToArray;
    pointerToArray = basicArray; // not & operator (because 'basicArray' is also a pointer)
    cout << "pointerToArray value: " << *pointerToArray << endl;
    printArray(basicArray, ARRAY_LEN);

    // Change some values to the array
    pointerToArray++;
    *pointerToArray = 44;
    // cout << pointerToArray << endl;
    *(pointerToArray + 2) = 1234;
    // cout << pointerToArray << endl;
    *(pointerToArray - 1) = 14; // 016 - octa
    printArray(basicArray, ARRAY_LEN);

    *basicArray = 1111;
    *(basicArray + 1) = 2222;
    printArray(basicArray, ARRAY_LEN);
    // Pointer arithmetics (visual representation) -> http://www.cplusplus.com/doc/tutorial/pointers/

    pointerToArray = basicArray;
    *(pointerToArray++) = 999; // Increment pointer but dereference the unincremented address
    // previous line is the same as -> *pointerToArray++ (because inc/dec have greater precendence over dereferencing -> *)
    printArray(basicArray, ARRAY_LEN);
    *pointerToArray =  888;
    printArray(basicArray, ARRAY_LEN);

    ++(*pointerToArray); // Dereference a pointer and increase value it points to
    // previous line is the same as ++*pointerToArray, also the same as *pointerToArray++
    printArray(basicArray, ARRAY_LEN);

    /// HOMEWORK
    // Print array elements
        // Function void printArrayByPtr(const float* arrayPointer, int arrayLength)
    // Increment every array element by specified increment step
        // Function void increment_by(int* startPointer, int* endPointer, int incrStep = 2)
        // Can previous function be written as -> void increment_by(const int* startPointer, const int* endPointer, int incrStep = 2)
    // Replace every occurence of the specified character with another specified character
        // void replaceBy(char * characterSequence, char replaceChar, char toReplaceBy)
        // HINT: Remember that character arrays end with '\0'. You do not need the length of the sequence, just iterate from the start until you find the \0 element.
    float myFloatArray[] = { 2.0f, 3.5f, 3490.3f };
    printArrayByPtr(myFloatArray, 3);

    const int INCARRAY_LEN = 5;
    int incArray[] = { 10, 20, 30, 40, 50 };
    printArray(incArray, INCARRAY_LEN);
    increment_by(incArray, incArray + INCARRAY_LEN, 4);
    printArray(incArray, INCARRAY_LEN);

    char mySequence[] = "this works, be happy!";
    replaceBy(mySequence, ' ', '_');
    cout << mySequence << endl;

    // NULL pointers (void pointers, pointers to pointers)
    int * ptr;
    // What is the value of ptr ?
    cout << "Uninitialized pointer: " << ptr << endl; // Undefined random value in memory
    ptr = &incArray[8934]; // Valid, but this points to 'out of bound' memory
    // cout << "Out of bound array memory: " << *ptr << endl; // RUNTIME ERROR
    int * myNullPtr = NULL; // or nullptr or 0 // defined value that points to nothing (no address)
    cout << "Value of NULL ptr: " << myNullPtr << endl;

    /// HOMEWORK
        // Find element, print that element or ~'Not found' if the element is not in the given array
        // double* findMe(double doubleArray[], int length, double elementToFind);
    int DOUBLE_ARRAY_LEN = 6;
    double myDoubleArray[] = { 23.23, 903.3, 1.0, 7777.777, 4309.1, 9999.999 };
    double *elementPtr = findMe(myDoubleArray, DOUBLE_ARRAY_LEN, 7777.777);
    if (elementPtr == NULL)
        cout << "I didn't find it." << endl;
    else
        cout << "I found the element you were looking for. Address is: " << elementPtr << " value is: " << *elementPtr << endl;
}

#pragma region Helper functions implementations
void printArray(int a[], int len)
{
    cout << "Array:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printArrayByPtr(const float* arrayPointer, int arrayLength)
{
    cout << "Array (by ptr print): " << endl;
    for (int i = 0; i < arrayLength; i++)
        cout << *arrayPointer++ << " ";
    cout << endl;
}

void increment_by(int* startPointer, int* endPointer, int incrStep)
{
    while (startPointer != endPointer)
    {
        *startPointer += incrStep;
        startPointer++;
    }
}

//void increment_by(const int* startPointer, const int* endPointer, int incrStep)
//{
//    // int* current = startPointer; // COMPILER ERROR invalid conversion from const int * to int *
//    while (startPointer != endPointer)
//    {
//        // *current += incrStep;
//        // current++;
//        *startPointer += incrStep; // COMPILER ERROR *startPointer is a read-only location
//        startPointer++;
//    }
//}

void replaceBy(char * characterSequence, char replaceChar, char toReplaceBy)
{
    while (*characterSequence != '\0')
    {
        if (*characterSequence == replaceChar)
            *characterSequence = toReplaceBy;

        characterSequence++;
    }
}

double* findMe(double doubleArray[], int length, double elementToFind)
{
    cout << "Looking for " << elementToFind << " element..." << endl;
    int i = 0;
    while (i < length)
    {
        if (doubleArray[i] == elementToFind)
            return &doubleArray[i];

        i++;
    }
    return NULL;
}
#pragma endregion
