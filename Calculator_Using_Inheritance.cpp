#include <bits/stdc++.h>

using namespace std;

class SimpleCalculator
{
public:
    void add(float a, float b)
    {
        cout << "The sum is : " << a + b << '\n';
    }

    void difference(float a, float b)
    {
        cout << "The difference is : " << a - b << '\n';
    }

    void product(float a, float b)
    {
        cout << "The product is : " << a * b << '\n';
    }

    void divide(float a, float b)
    {
        cout << "The division is : " << a / b << '\n';
    }
};

class ScientificCalculator : public SimpleCalculator
{
public:
    void logarithm(float value)
    {
        cout << "The log is " << log(value) << '\n';
    }
    void sine(float angleR)
    {
        cout << "The sine is : " << sin(angleR) << '\n';
    }

    void cosine(float angleR)
    {
        cout << "The cosine is : " << cos(angleR) << '\n';
    }

    void tangent(float angleR)
    {
        cout << "The tangent is : " << tan(angleR) << '\n';
    }
};

int main(void)
{
    ScientificCalculator c;
    float input1, input2;
    int choice;
    do
    {
        cout << "What do you want to perform?\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Sine\n6. Cosine\n7. Tangent\n8. Logarithm\n(Enter 0 to quit): ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Quitting the calculator...";
            break;
        case 1:
            cout << "Enter the two numbers: ";
            cin >> input1 >> input2;
            c.add(input1, input2);
            break;
        case 2:
            cout << "Enter the two numbers: ";
            cin >> input1 >> input2;
            c.difference(input1, input2);
            break;
        case 3:
            cout << "Enter the two numbers: ";
            cin >> input1 >> input2;
            c.product(input1, input2);
            break;
        case 4:
            cout << "Enter the two numbers: ";
            cin >> input1 >> input2;
            c.divide(input1, input2);
            break;
        case 5:
            cout << "Enter the angle in radians: ";
            cin >> input1;
            c.sine(input1);
            break;
        case 6:
            cout << "Enter the angle in radians: ";
            cin >> input1;
            c.cosine(input1);
            break;
        case 7:
            cout << "Enter the angle in radians: ";
            cin >> input1;
            c.tangent(input1);
            break;
        case 8:
            cout << "Enter the value you want the log of: ";
            cin >> input1;
            c.logarithm(input1);
            break;
        default:
            cout << "Enter a valid choice!!!\n";
            break;
        }
    } while (choice);
    return 0;
}