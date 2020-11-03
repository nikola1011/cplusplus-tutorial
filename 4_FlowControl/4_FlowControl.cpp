#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Enter a number: " << endl;
    cin >> x;

    if (x == 10)
        cout << "You entered number that is 10." << endl;

    if (x > 0)
    {
        cout << x << " is positive" << endl;
    }
    else
    {
        cout << x << " is not positive. I'll fix it for ya." << endl;
        x *= -1;
        cout << "X is now: " << x << endl;
    }


    int i = 0;
    cout << "Count to 10, please (while loop)..." << endl;
    while (i < 10)
    {
        cout << i << endl;
        i++;
    }

    i = 0;
    cout << "Count to 10, again please (do while loop)..." << endl;
    do
    {
        cout << i << endl;
        i++;
    } while (i < 10);

    do
    {
        cout << "This happens once." << endl;
    } while (false);

    cout << "Count to 10, again please (for loop)..." << endl;
    for (cout << "Loop starting." << endl, i = 0; i < 10; i++) // initialization ; condition ; on loop statement
    {
        cout << i << endl;
    }

    for (i = 10; i > 0; i--)
    {
        if (i % 2 == 0)
            continue;
        
        cout << "Looping: " << i << endl;
    }


    while (true)
    {
        cout << "Please enter a number. Zero to stop." << endl;
        cin >> x;
        cout << "You entered: " << x << endl;
        if (x == 0)
        {
            cout << "Exiting loop." << endl;;;;;;;;;;;;;;; // NO COMPILER ERROR
            break;
        }
    }

    do
    {
        cout << "Please enter a number again. Zero to stop." << endl;
        cin >> x;
        cout << "You entered: " << x << endl;
    } while (x != 0);
}