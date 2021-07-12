#include <iostream>

using namespace std;

class Base // It is an abstract base class
{
protected:
    int baseInt;

public:
    virtual void greet(void) = 0; //pure virtual function
};

class Derived : public Base
{
public:
    void greet(void) // greet() overrider
    {
        cout << "Good morning Neeraj\n";
    }
};

int main(void)
{
    Base *ptr = NULL;
    Derived object;
    ptr = &object;
    ptr->greet();
    return 0;
}