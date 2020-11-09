#include <iostream>

using namespace std;

void printArray(double a[], int n);

void printMatrix(int a[][10], int rows = 5) // Historical reasons (this can be made more robust with the use of pointers)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			// cout << a[i][j] << "  ";
			printf("%6d ", a[i][j]); // printf (from C) in also included in 'std' namespace
		}
		
		cout << endl;
	}
}

int main()
{
	///  Single arrays

	int myArray[3]; // Array size - '3' must be a constant value known at COMPILE TIME

	const int ARRAY_LENGHT = 93;
	float myFloatArray[ARRAY_LENGHT]; // ARRAY_LENGHT must be declared 'const', otherwise COMPILER ERROR will be emitted

	double myDoubleArray[5] = { 1, 2, 3 };
	cout << myDoubleArray[0] /* first element - indexing starts from 0 */ << " " << myDoubleArray[4] /* last element */ << endl;

	cout << "Value of myDoubleArray[2] = " << myDoubleArray[2] << endl;
	myDoubleArray[2] = 2222.3809; // No 'f' suffix to specify double (as all floating point literals are 'double' by default)
	cout << "Value of myDoubleArray[2] = " << myDoubleArray[2] << endl;

	// cout << myDoubleArray[9023] << endl; // RUNTIME ERROR
	printArray(myDoubleArray, 5);

	/// Character arrays

	char charArray[4];
	char myStringByCharacters[] = { 'M', 'y', ' ', 'S', 't', 'r', 'i', 'n', 'g', '\0' }; // By convention, the end of strings represented in character sequences is signaled by a special character: the null character, whose literal value can be written as '\0' 
	cout << myStringByCharacters << endl;
	char myStringByCharactersSimpleInit[] = "I like this way better"; // '\0' is implicit at the end
	cout << myStringByCharactersSimpleInit << " " << strlen(myStringByCharactersSimpleInit) /* count the characters, excluded \0 from the count */ << endl;

	// string to char[] and other way around
	//string s = myStringByCharacters; // implicit conversion
	//string q = "blabla";
	//const char *bla = q.c_str(); // convert form 'string' to 'char[]'

	/// Arrays of arrays of arrays of arrays
	
	int matrix[5][10] = { 11111 };
	matrix[3][2] = 392;
	printMatrix(matrix);

	int hyperCubes[4][10][5][5]; // 4 * 10 * 5 * 5 elements
}

void printArray(double a[], int n)
{
	cout << "printArray: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
