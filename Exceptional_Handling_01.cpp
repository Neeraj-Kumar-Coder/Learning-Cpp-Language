#include <iostream>
#include <stdexcept>

using namespace std;

int main(void)
{
    int numerator, denominator, result;
    cout << "Enter the numerator and the denominator: ";
    cin >> numerator >> denominator;
    try
    {
        if (!denominator)
        {
            throw "Zero Division Error\n";
        }
        result = numerator / denominator;
        cout << "The result after division is: " << result << '\n';
    }
    catch (const char *ex)
    {
        cout << "Exception occured: " << ex;
    }
    return 0;
}