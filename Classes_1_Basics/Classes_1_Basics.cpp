#include <iostream>

using namespace std;

// Classes allow programming using object-oriented paradigm
// Classes are structs that contain members which can be either common variables or functions
// Apart from that, classes also have access specifiers (which declare the access rights to the given member(s) of the class)
// Access specifiers are noted by keywords: 'private', 'protected', 'public'
    // private   -  members accessible from inside other class members + "friend" classes
    // protected -  members accessible from inside other class members + "friend" classes + derived classes' members
    // public    -  members accessible from anywhere

    // If not specified 'private' access modifier is implicit.
// An object is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.

// Class declaration
// class <class_name_identifier> { <class_body - members> };
class Person {
    // If not specified, 'private' access modifier is default one
    int age;
    const char* name;
    int sleepHours = 5;

public: // From this point onward all declared members have 'public' as their access modifier
    bool alive = true;

    // Constructor(s)
    // Automatically called whenever a new object of this class is created (CANNOT be called explicitly)
    // No return type. Function name that matches class name.
    // Constructor with no parameters is also known as the default constructor
    // The default constructor is called when an object is created with no arguments specified at its' declaration
    // Default constructor is implicitly created by compiler, BUT ONLY if no other constructors exist
    // (if other constructor overloads exist, default constructor is not "generated" by compiler and must be explicitly defined alongside those constructors)
    Person()
    {
        name = "John Doe";
        age = 0;
        // No return statement (just initialize class members)
    }

    // Constructor containing some parameters
    Person(const char* name, int age)
    {
        // The keyword 'this' represents a POINTER to the object whose member function is being executed.
        // It referes to the object itself.
        // Because it's a pointer '->' is used for dereferencing and member access.
        this->name = name;

        // this->age can be written as (*this).age as would have the same effect.
        (*this).age = age;
    }

    // Destructor
    // Automatically called when object is deleted/disposed (lifetime of an object ends).
    // No return type. Function name that matches class name with '~' prefix.
    // Has no parameters.
    // The purpose of the destructor is to free the resources that the object may have acquired during its lifetime.
    ~Person() { /* No need for any deletion as nothing was allocated with 'new' keyword */ }

    // All function implementations within inside the class are considered 'inline'
    void introduce()
    {
        cout << "Hello, my name is: " << name << " and I am " << age << " years old." << endl;
    }

    // Separated implementations from declarations are NOT inline, unless explicitly specified so with 'inline' keyword
    void sleep();
    void smile();
};

void Person::sleep()
{
    cout << "Going to sleep." << endl;
    for (int i = 1; i <= sleepHours; i++)
    {
        cout << "I am sleeping... " << i << " hours passed. " << endl;
    }
    cout << "I am awake now." << endl;
}

void Person::smile()
{
    cout << ":)" << endl;
}

int main()
{
    // Create object of a given class. Default constructor is called
    Person p1;
    // Class declarations are similar to any variable declaration
    int myVar;
    // NOTE: When initializing an object with default constructor '()' parenthesis MUST NOT be included
    // Person p1(); // This will declare a function 'p1' whose return type is 'Person'. Probably not intented.

    // 'myBestFriend' is a object of type Person.
    Person myBestFriend("Jack Napier", 31);

    // To access class members use '.'
    myBestFriend.introduce();
    // NOTE: Only members with proper access modifiers CAN be accessed.
    // cout << "Age: " << myBestFriend.age << endl; // COMPILER ERROR - member age is inaccessible

    myBestFriend.smile();
    myBestFriend.sleep();

    // Pointers to classes are also allowed.
    Person* p2 = new Person("Person2", -293);
    cout << "Is person alive ? " << (*p2).alive << endl;

    cout << "Is person alive ? " << p2->alive << endl;
    p2->introduce();
    // The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects that have members.
    // p->x is equal to (*p).x

    // Object 'p2' is deleted, call its' destructor
    delete p2;

    return 0;
} // Objects statically declared go out of scope here (and their destructors are called)

/// HOMEWORK
// Create a class Car
    // Have private fields: char * model, int productionYear, float velocity, float accelerationInSeconds

    // Has default constructor: Car()
    // Has a constuctor with parameters
        // Car(char* model, int prodYear, float velocity, float accelerationInSeconds)
    // HINT: Remember that constructors MUST have 'public' access modifiers
    // Has destructor that prints the "Car {model} is destroyed."

    // Has public functions:
        // void print() - prints all fields on the standard output
        // bool isSuperCar(float limit) - returns 'true' if the Car's velocity is greater than the 'limit' argument, otherwise 'false'
        // void accelerate(float acceleration) - increment Car's velocity by acceleration parameter

// In main function:
    // Create Car (in static memory) with default and constructor with parameters
        // Print each Car's fields with 'print()' function
        // REMEMBER that everything should be initiliazed properly.

    // Create a 'Lamborghini' Car object in "dynamic" memory with constructor with parameters
        // Print its specifications (object fields)
        // See if it's a super car (use isSuperCar function)
            // If no, use 'accelerate' function UNTIL Lamborghini becomes a super car.
            // If yes, write "This is a super car"

    // delete/deallocate all memory before program termination
        // Place `cout << "Constructor call" << endl;` in Constructors
        // And `cout << "Destructor call" << endl;` in Destructors
        // To see the objects' lifetime
