#include <iostream>
#include "Car.h"

using namespace std;
// .cpp file ; .h file
// (keyword this)
// static methods
// inline methods
// input/output examples (no operator overloading)

//rv4
// copy constructor, operators
// istream, ostream operators (input output examples - << and >> operators overloading)
// friend

int main()
{
    Car myCar("Lamborghini", 2018, 239.3f, 3.31f);

    myCar.print();
    float LIMIT = 300;
    while (!myCar.isSuperCar(LIMIT))
    {
        cout << "Still not a super car. Accelerating..." << endl;
        myCar.accelerate(10);

        cout << "Is super car? " << myCar.isSuperCar(LIMIT) << endl;
    }

    return 0;
}
