#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

class Car
{
    char* model;
    int productionYear;
    float velocity, accelerationInSeconds;

public:
    Car();
    Car(char* model, int prodYear, float velocity, float accelerationInSeconds);
    ~Car();
    void print();
    bool isSuperCar(float limit);
    void accelerate(float acceleration);
 };

#endif // CAR_H_INCLUDED
