#include <iostream>

using namespace std;

class Complex
{
    int a;
    int b;

public:
    void getNumber(int num1, int num2)
    {
        a = num1;
        b = num2;
    }

    void addNumbers(Complex, Complex);
    void printNumber(void)
    {
        cout << "The complex number is : " << a << " + " << b << "i\n";
    }
};

void Complex::addNumbers(Complex z1, Complex z2)
{
    a = z1.a + z2.a;
    b = z1.b + z2.b;
}

int main(void)
{
    Complex z1, z2, z3;
    z1.getNumber(5, 7);
    z1.printNumber();
    z2.getNumber(6, 9);
    z2.printNumber();
    z3.addNumbers(z1, z2);
    z3.printNumber();
    return 0;
}