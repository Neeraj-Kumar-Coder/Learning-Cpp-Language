#include <iostream>

using namespace std;

class Complex;

class Calculator
{
public:
    Complex sumNumbers(Complex, Complex);
};

class Complex
{
    int x;
    int y;
    // friend Complex Calculator::sumNumbers(Complex, Complex); // This is used when we want to give permission to certain methods of a class
    friend class Calculator; // This is used when we want to give permission to every method of the class

public:
    void getNumber(int, int);
    void printNumber(void)
    {
        cout << "The number is : " << x << " + " << y << "i\n";
    }
};

Complex Calculator::sumNumbers(Complex z1, Complex z2)
{
    Complex result;
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

void Complex::getNumber(int num1, int num2)
{
    x = num1;
    y = num2;
}

int main(void)
{
    Complex z1, z2;
    z1.getNumber(5, 8);
    z2.getNumber(6, 7);
    Calculator calc;
    Complex z3 = calc.sumNumbers(z1, z2);
    z3.printNumber();
    return 0;
}