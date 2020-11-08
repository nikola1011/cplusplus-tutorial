#include <iostream>

using namespace std;

// All memory needs determined before the program execution is located on stack. ("static" memory)
// However, memory can be allocated in runtime (while program is executing), thus making this memory "dynamic".
// Dynamic memory is allocated on a structure called heap.

int main()
{
    // Static array - because array length is known at compile time
    int myStaticArray[32];

    int arrayLength = 0;
    cout << "Enter array length: " << endl;
    cin >> arrayLength;
    // Dynamic array - size of needed memory is known at runtime
    int* dynamicArray; // Declare a pointer for a array
    // Allocate memory for array by using 'new' keyword.
    dynamicArray = new int[arrayLength]; // There's no guarantee that the requested memory will be granted (memory is limited, it is handled by OS)

    cout << "Array values: " << endl;
    for (int i = 0; i < arrayLength; i++)
        cout << dynamicArray[i] << " "; // Random memory values

    // A memory for a single element can also be allocated
    int* dynamicInt = new int;
    cout << "\nSingle element memory: " << *dynamicInt << endl;

    // The allocated memory is the responsibility of the program.
    // When the program allocates memory it should also deallocate it (free it for other programs to use it).
    // This is done with 'delete' keyword.
    delete dynamicInt;
    delete [] dynamicArray;

    // 'delete' does not immediately free memory for performance reasons.
    // But accessing freed memory causes undefined behaviour. A runtime error can or may not occur.
    // After 'delete' statement the program is promising that it will no longer use that memory, or the pointer that points to that memory.
    // If that promise is not kept, program has undefined consequences.
    /// BAD PROGRAMMING
    // cout << dynamicInt << " " << *dynamicInt << endl;
    // *dynamicInt = 3;
    // dynamicArray[1] = 3;
    /// BAD PROGRAMMING

    /// HOMEWORK
    // Create a loop that allocates and does not free array
        // See program's memory consumption in Task Manager (CTRL + SHIFT + ESC to open Task Manager window, with your program and see memory consumption)
    // Apply the same allocating logic but free memory
        // Notice the difference
    // What happens if you delete NULL pointer
        // int* x = NULL;
        // delete x;
        // What will happen ?

    return 0;
}
