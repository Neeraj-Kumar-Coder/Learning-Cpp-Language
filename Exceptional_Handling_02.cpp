#include <iostream>
#include <stdexcept>

using namespace std;

int main(void)
{
    int numerator, denominator, result;
    cout << "Enter the value of numerator and denominator: ";
    cin >> numerator >> denominator;
    try
    {
        if (!denominator)
        {
            throw "Zero Division Error\n";
            // throw 99;
        }
        result = numerator / denominator;
        cout << "The result after division is: " << result << '\n';
    }
    catch (const char *exc)
    {
        cout << "Exception Occured: " << exc;
    }
    catch (...)
    {
        cout << "General Exception!\n";
    }
    return 0;
}