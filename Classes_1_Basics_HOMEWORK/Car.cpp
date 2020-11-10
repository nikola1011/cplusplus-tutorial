#include <iostream>
#include "Car.h"

using namespace std;

Car::Car()
{
    cout << "Default constructor CALL" << endl;
    model = "NONE";
    productionYear = velocity = accelerationInSeconds = 0;
}

Car::Car(const char* model, int prodYear, float velocity, float accelerationInSeconds)
{
    cout << "Constructor CALL" << endl;
    this->model = model;
    productionYear = prodYear;
    this->velocity = velocity;
    this->accelerationInSeconds = accelerationInSeconds;
}

Car::~Car()
{
    cout << "Destructor CALL" << endl;
}

void Car::print()
{
    cout << "Model: " << this->model << endl;
    cout << "Production year: " << this->productionYear << endl;
    cout << "Velocity: " << this->velocity << endl;
    cout << "Acceleration in seconds: " << this->accelerationInSeconds << endl;
}

bool Car::isSuperCar(float limit)
{
    return this->velocity >= limit;
}

void Car::accelerate(float acceleration)
{
    this->velocity += acceleration;
}
