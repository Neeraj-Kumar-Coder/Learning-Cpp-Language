#include <iostream>

using namespace std;

class Number
{
    int num;

public:
    Number(void) {}
    Number(int a)
    {
        num = a;
    }
    Number(Number &object) // Copy constructor
    {
        cout << "Copy constructor called!\n";
        num = object.num;
    }
    void printNumber(void);
};

void Number::printNumber(void)
{
    cout << "The number is : " << num << '\n';
}

int main(void)
{
    Number a, b, c;
    a = Number(5);
    b = Number(7);
    c = a;       // copy constructor donot run!
    Number d(a); // copy constructor called!

    a.printNumber();
    b.printNumber();
    c.printNumber();
    d.printNumber();
    return 0;
}