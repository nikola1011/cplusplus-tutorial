#pragma once

class Car
{
    const char* model;
    int productionYear;
    float velocity, accelerationInSeconds;

public:
    Car();
    Car(const char* model, int prodYear, float velocity, float accelerationInSeconds);
    ~Car();
    void print();
    bool isSuperCar(float limit);
    void accelerate(float acceleration);
};
