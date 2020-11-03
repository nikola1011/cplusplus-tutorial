#include <iostream>
// Named entities, such as variables, functions, and compound types need to be declared before being used in C++.
// An entity declared outside any block has global scope, meaning that its name is valid anywhere in the code.
// While an entity declared within a block, such as a function or a selective statement, has block scope, and is only visible within the specific block in which it is declared, but not outside it.

using namespace std;

int globalVariable = 392;

// Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes,
// giving them namespace scope. 
namespace myNamespace
{
    int x = -1, y = -10;
}

namespace anotherNamespace
{
    float myVariableThatIUseOften = 3.14f;
    void myFunctionThatIUseOften()
    {
        cout << "myVariableThatIUseOften: " << myVariableThatIUseOften << endl;
    }
}

int main()
{
    cout << "globalVariable: " << globalVariable << endl;
    int x = 23;
    cout << "local x: " << x << endl;
    {
        cout << "Before inner block declaration: " << x << endl;
        int x = 1;
        cout << "After inner block declaration: " << x << endl;
        {
            int x = 2;
            cout << x << endl;
            {
                int x = 3;
                cout << x << endl;
            }
        }
    }

    cout << "Namspace x: " << myNamespace::x << endl; // No collision with global or local x

    using namespace anotherNamespace;
    myFunctionThatIUseOften(); // anotherNamespace::myFunctionThatIUseOften();

    // Remember that 'std' is also just another namespace (that's why 'cout' can be written without 'std::' prefix as 'cout' belongs in 'std' namespace)
}

void testVisibility()
{
    // using namespace anotherNamespace;
    // myFunctionThatIUseOften(); // COMPILLER ERROR (if 'using namespace anotherNamespace' not declared)
}