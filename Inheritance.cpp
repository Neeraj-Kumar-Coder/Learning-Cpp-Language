#include <iostream>

using namespace std;

// Base Class
class A
{
private:
    int member1;

public:
    A(void) {} // Default constructor needed for inheritance as the inherited class automatically calls the constructor of base class
    A(int data)
    {
        member1 = data;
    }
    void printData(void)
    {
        cout << member1 << '\n';
    }
};

// Derived Class
class B : public A
{
private:
    int member2;

public:
    B(int data)
    {
        member2 = data;
    }
    // void printData(void) // Commenting this will call the printData() function of the Base class
    // {
    //     cout << member2 << '\n';
    // }
};

int main(void)
{
    A a(-1);
    B b(5);
    a.printData();
    b.printData();
    return 0;
}