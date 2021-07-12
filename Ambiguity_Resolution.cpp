#include <iostream>

using namespace std;

class Base1
{
public:
    void greet(void)
    {
        cout << "I am a programmer\n";
    }
};

class Base2
{
public:
    void greet(void)
    {
        cout << "Main ek prograamar hoon\n";
    }
};

class Base3
{
public:
    void greet(void)
    {
        cout << "Ich bin Programmierer\n";
    }
};

class Derived : public Base1, public Base2, public Base3
{
    // Wihtout this explicit definition, the call to the greet() method of the derived class is ambigious
public:
    void greet(void)
    {
        Base2::greet(); // This will tell the compiler that which greet() method to use
    }
};

int main(void)
{
    Base1 a;
    Base2 b;
    Base3 c;
    a.greet();
    b.greet();
    c.greet();

    Derived d;
    d.greet();
    return 0;
}