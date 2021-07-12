#include <iostream>

using namespace std;

class Complex
{
    // Class for complex number : a + bi
    int realPart;    // a
    int complexPart; // b

public:
    Complex(int, int); //Constructor declaration (Constructor is automatically invoked when the object is created)
    // Complex(void); // Default constructor as it takes no arguments

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

// Definition of default constructor
// Complex ::Complex(void)
// {
//     realPart=1;
//     complexPart=1;
// }

int main(void)
{
    Complex z1(3, 4);           // Implicit call
    Complex z2 = Complex(5, 6); // Explicit call
    z1.printNumber();
    z2.printNumber();
    return 0;
}