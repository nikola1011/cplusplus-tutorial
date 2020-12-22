#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack 
{
private:
    T* elements;
    int current = 0;
    int capacity = 0;

public:

    Stack(int capacity)
    {
        this->elements = new T[capacity];
        this->capacity = capacity;
        this->current = 0;
    }
    ~Stack()
    {
        delete[] this->elements;
    }

    void push(const T& elem);
    T pop();

    bool empty()
    {
        return this->current == 0;
    }
    bool isFull()
    {
        return this->current == this->capacity;
    }

    friend ostream& operator<< <T>(ostream& output, const Stack<T>& obj);
};

template <class T>
void Stack<T>::push(const T& elem)
{
    if (!this->isFull())
    {
        cout << "Inserting element: " << elem << endl;
        this->elements[this->current++] = elem;
    }
}

template <class T>
T Stack<T>::pop() {
    if (!this->empty()) 
    {
        cout << "Removing element " << this->elements[this->current - 1] << endl;
        return this->elements[--this->current];
    }
}

template <class T>
ostream& operator<<(ostream& output, const Stack<T>& obj)
{
    for (int i = 0; i < obj.current; i++)
    {
        output << obj.elements[i] << " " << endl;
    }
    return output;
}