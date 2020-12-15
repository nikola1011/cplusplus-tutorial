#include <iostream>

using namespace std;

// Abstract class - if a class contains at LEAST ONE pure virtual function, it is an abstract class
class Polygon 
{
protected:
    int width, height;

public:
    void setValues(int a, int b)
    {
        width = a; height = b;
    }

    // virtual <function declaration> = 0;
    // Pure virtual function
    virtual int area() = 0;

    void printArea()
    {
        // Pure virtual function can be called inside abstract class
        cout << this->area() << '\n';
    }
};

class Rectangle : public Polygon 
{
public:
    int area()
    {
        return (width * height);
    }
};

class Triangle : public Polygon 
{
public:
    int area()
    {
        return (width * height / 2);
    }
};

int main()
{
    // Abstract classes cannot be instantiated
    // Polygon p; // Compiler error
    // Polygon p = new Polygon(); // Compiler error
    
    Rectangle rect;
    Triangle triangle;
    
    Polygon* polyRect = &rect; // Pointer of abstract class can exist
    Polygon* polyTriangle = &triangle;

    polyRect->setValues(4, 5);
    polyTriangle->setValues(4, 5);

    polyRect->printArea();
    polyTriangle->printArea();

    // Direct pure virtual function call
    cout << "Area for Rectangle " << polyRect->area() << endl;
    cout << "Area for Triangle " << polyTriangle->area() << endl;

    return 0;
}
