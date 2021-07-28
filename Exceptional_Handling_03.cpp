#include <iostream>
#include <stdexcept>

using namespace std;

class Exception
{
public:
    const char *what(void)
    {
        return "Zero Division Error\n";
    }
};

int main(void)
{
    int numerator, denominator, result;
    cout << "Enter the value of numerator and denominator: ";
    cin >> numerator >> denominator;
    try
    {
        if (!denominator)
        {
            Exception e;
            throw e;
        }
        result = numerator / denominator;
        cout << "The result after division is: " << result << '\n';
    }
    catch (const char *exc)
    {
        cout << "Exception Occured: " << exc;
    }
    catch (Exception exc)
    {
        cout << "Exception Occured: " << exc.what();
    }
    catch (...)
    {
        cout << "General Exception!\n";
    }
    return 0;
}