#include <iostream>

using namespace std;

class Base1
{
    int base1int;

public:
    Base1(int key) : base1int(key)
    {
        cout << "Constructor of Base1 run\n";
    }
};

class Base2
{
    int base2int;

public:
    Base2(int key) : base2int(key)
    {
        cout << "Constructor of Base2 run\n";
    }
};

// class Derived : public Base2, public Base1
class Derived : public Base1, public Base2
{
    int derived1, derived2;

public:
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Constructor of Derived run\n";
    }
};

int main(void)
{
    Derived d(1, 2, 3, 4);
    return 0;
}