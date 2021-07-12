#include <iostream>

using namespace std;

class Base1
{
protected:
    int base1int;

public:
    void setBase1int(int value)
    {
        base1int = value;
    }
};

class Base2
{
protected:
    int base2int;

public:
    void setBase2int(int value)
    {
        base2int = value;
    }
};

class Derived : public Base1, public Base2
{
public:
    void display(void)
    {
        cout << "Value 1 = " << base1int << "\nValue 2 = " << base2int << '\n';
    }
};

int main(void)
{
    Derived a;
    a.setBase1int(15);
    a.setBase2int(30);
    a.display();
    return 0;
}