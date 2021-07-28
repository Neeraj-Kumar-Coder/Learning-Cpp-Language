#include <iostream>

using namespace std;

class Base
{
public:
    virtual void BasePrint(void)
    {
        cout << "This is base print\n";
    }
};

class Derived1 : public Base
{
public:
    void Derived1print(void)
    {
        cout << "This is derived1 print\n";
    }
};

class Derived2 : public Base
{
public:
    void Derived2print(void)
    {
        cout << "This is derived2 print\n";
    }
};

int main(void)
{
    Base *ptr = new Derived1;

    Derived1 *caster1 = dynamic_cast<Derived1 *>(ptr);
    if (caster1 != NULL)
        caster1->Derived1print();
    Derived2 *caster2 = dynamic_cast<Derived2 *>(ptr);
    if (caster2 != NULL)
        caster2->Derived2print();
    return 0;
}