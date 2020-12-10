#include <iostream>

using namespace std;

static int totalVehicles = 0;

class Vehicle
{
    char* engine;

protected:
    int serialNumber;
    float speed;
    
    void changeTires()
    {
        cout << "VEHICLE " << this->serialNumber << ", Changing tires" << endl;
    }
public:
    int productionYear;

    Vehicle()
    {
        this->serialNumber = ++totalVehicles;
        cout << "VEHICLE " << this->serialNumber << ", Constructor call." << endl;
    }
    Vehicle(const char* engine) : Vehicle()
    {
        this->engine = (char*)engine;
    }
    virtual ~Vehicle()
    {
        cout << "~VEHICLE " << this->serialNumber << ", Destructor call." << endl;
    }

    virtual void printAll()
    {
        cout << "VEHICLE " << this->serialNumber << " characteristics" << endl;
        cout << "\t" << "Engine: " << this->engine << "\n\t"
            << "Speed: " << this->speed << "\n\t"
            << "Production year: " << this->productionYear << endl;
    }
};

class Car : public Vehicle
{
    bool cabrio;

public:
    Car(bool isCabrio = false)
    {
        cout << "CAR " << this->serialNumber << ", Constructor call." << endl;
    }
    ~Car()
    {
        cout << "~CAR " << this->serialNumber << ", Destructor call." << endl;
    }

    void increaseSpeed(float speed)
    {
        this->changeTires(); // changeTires func - inherited from Vehicle class

        cout << "Increasing speed..." << endl;
        this->speed += speed; // speed - inherited from Vehicle class
        cout << "CAR " << this->serialNumber << " speed is now: " << this->speed << endl;
    }

    virtual void printAll()
    {
        cout << "CAR " << this->serialNumber << " characteristics" << endl;
        cout << "\t" /*<< this->engine - INACCESSIBLE */
            << "Speed: " << this->speed << "\n\t"
            << "Production year: " << this->productionYear << "\n\t"
            << "Carbrio: " << this->cabrio << endl;
    }

    /// Things that are NEVER inherited
    //
    // Constructors and Destructor    
    // Assignment operator members (operator=)
    // Friends
    // private members
};

int main()
{
    cout << "\t\tSTATIC MEMORY -----------------------------------------" << endl;

    Vehicle v1("Engine1");
    cout << "v1 productionYear: " << v1.productionYear << endl;
    v1.printAll();

    Car c1;
    cout << "c1 productionYear: " << c1.productionYear << endl;
    c1.printAll(); // Overloaded virtual function call
    
    c1.increaseSpeed(52.1f);

    cout << "\t\tDYNAMIC MEMORY -----------------------------------------" << endl;

    Vehicle* v3 = new Vehicle("Engine3");
    v3->printAll();

    Car* c4 = new Car(true);
    c4->increaseSpeed(102);
    c4->printAll();

    delete v3;
    delete c4;

    cout << "\t\tPOINTERS -----------------------------------------" << endl;
    Vehicle* basePtr = new Car(true);
    basePtr->printAll();

    basePtr = &v1;
    basePtr->printAll();

    // Car* derivedPtr = &v1; // Compiler error, derived cannot point to base class

    Car* derivedPtr = new Car();
    Vehicle* basePtr2;
    basePtr2 = (Vehicle*)derivedPtr;
    basePtr2->printAll();
    
    delete basePtr2; // Destructor must be virtual when deleting derived instance with a base pointer instance (in order for derived class' destructor to be called)
}