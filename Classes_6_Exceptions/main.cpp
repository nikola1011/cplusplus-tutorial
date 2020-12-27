#include <iostream>

using namespace std;

/// Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring control to special functions called handlers.

int main()
{
    try
    { // beginning of a block that may cause an exception
        int arraySize = 0;
        
        cout << "Enter array size:" << endl;
        cin >> arraySize;

        int* myArray = new int[arraySize]; // This may create an exception
        cout << "Array allocated with size: " << arraySize << endl;
        cout << "No exception occured." << endl;
    } // end of a block that may cause an exception

    /*catch (bad_alloc& e)
    {
        cout << "Bad allocation exception: " << e.what() << endl;
    }*/
    catch (exception& e)
    {
        // If exception occurs in `try` block, appropriate catch handles the exception
        cout << "Standard exception: " << e.what() << endl;
    }
    /*catch (...)
    {
        cout << "Generic exception occured." << endl;
    }*/

    cout << "-------------------------------------------------------------" << endl;

    try
    {
        // Exceptions can be manually created using `throw`
        // throw <parameter>;

        throw 20; // This creates an exception ("throws" an exception)
        throw 202.328f;
        throw 'C';
        throw string("StringException");
        throw "Exception";
        throw exception("STD Exception message");
    }
    catch (int e)
    {
        cout << "Exception " << typeid(e).name() << " occured: " << e << endl;
    }
    catch (float e)
    {
        cout << "Exception " << typeid(e).name() << " occured: " << e << endl;
    }
    catch (char e)
    {
        cout << "Exception " << typeid(e).name() << " occured: " << e << endl;
    }
    catch (string e)
    {
        cout << "Exception " << typeid(e).name() << " occured: " << e << endl;
    }
    /*catch (MyCustomException e)
    {
        cout << "Exception occured: " << e << endl;
    }*/
    catch (exception& e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Generic exception occured." << endl;
    }
}