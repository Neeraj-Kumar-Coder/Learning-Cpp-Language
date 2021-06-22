#include <iostream>

using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Enter the value of num1: ";
    cin >> num1;
    cout << "Enter the value of num2: ";
    cin >> num2;
    cout << "The sum of the two numbers is: " << num1 + num2 << "\n";

    // Refrence Variable
    int a = 34;
    int &b = a; // 'b' is a refrence variable
    cout << a << "\n"
         << b;
    cout << "\nThe sizeof a: " << sizeof(a) << "\nThe sizeof b: " << sizeof(b) << "\n";

    // Constant Variables
    int const var = 10;
    cout << var << "\n";
    return 0;
}