#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace std;

int main()
{
    cout << "\n\nBASE static ------------------------------------------ " << endl;
    Base base;
    base.nonVirtualFunc();
    base.virtualFunc();

    cout << "\n\nDERIVED static ------------------------------------------ " << endl;
    Derived derived;
    derived.nonVirtualFunc();
    derived.virtualFunc(); 
    cout << "\n\nCall base function ------------------------------------------ " << endl;
    derived.callBaseFunctionTest();

    Base* basePtr;

    cout << "\n\nBASE ptr to BASE------------------------------------------ " << endl;
    basePtr = &base;
    basePtr->nonVirtualFunc();
    basePtr->virtualFunc();

    cout << "\n\nBASE ptr to DERIVED ------------------------------------------ " << endl;
    basePtr = &derived;
    basePtr->nonVirtualFunc();
    basePtr->virtualFunc();

    cout << "\n\nBASE dynamic ------------------------------------------ " << endl;
    Base* dynamicBase = new Base();
    dynamicBase->nonVirtualFunc();
    dynamicBase->virtualFunc();
    delete dynamicBase;

    cout << "\n\nDERIVED dynamic ------------------------------------------ " << endl;
    Derived* dynamicDerived = new Derived();
    dynamicDerived->nonVirtualFunc();
    dynamicDerived->virtualFunc();
    delete dynamicDerived;

    cout << "\n\nBASE ptr to DERIVED dynamic ------------------------------------------ " << endl;
    Base* baseDynamicPtr = new Derived();
    baseDynamicPtr->nonVirtualFunc();
    baseDynamicPtr->virtualFunc();
    delete baseDynamicPtr; // Destructor must be virtual when deleting derived instance with a base pointer instance (in order for derived class' destructor to be called)

    cout << "\n\nSTATIC MEMORY DESTRUCTORS: " << endl;
}