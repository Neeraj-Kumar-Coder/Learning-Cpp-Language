#include <iostream>

using namespace std;

class Complex
{
    // Class for complex number : a + bi
    int realPart;    // a
    int complexPart; // b

public:
    Complex(int, int); //Constructor declaration (Constructor is automatically invoked when the object is created)

    void printNumber(void)
    {
        cout << "The complex number is: " << realPart << " + " << complexPart << "i.\n";
    }
};

// Constructor definition : donot have any return value
Complex ::Complex(int num1 = 0, int num2 = 0)
{
    realPart = num1;
    complexPart = num2;

    // Anything here is executed when constructor is invoked!!!
    // cout<<"This will be executed when creating the objects\n";
}

int main(void)
{
    Complex z1(3, 4), z2(5, 6);
    z1.printNumber();
    z2.printNumber();
    return 0;
}