#include <iostream>

using namespace std;

class Base
{
protected:
    int a;

public:
    void setA(int num)
    {
        a = num;
    }
};

class Derived1 : virtual public Base
{
protected:
    int b = 10;
};

class Derived2 : virtual public Base
{
protected:
    int c = 20;
};

class Hybrid : public Derived1, public Derived2
{
public:
    void display(void)
    {
        cout << "The total score is: " << a + b + c;
    }
};

int main(void)
{
    Hybrid h;
    h.setA(20);
    h.display();
    return 0;
}