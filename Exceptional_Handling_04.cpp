#include <iostream>
#include <stdexcept>

using namespace std;

class Exception : public runtime_error
{
public:
    Exception(void) : runtime_error("Math Error: Attempt to divide by zero\n") {}
};

int main(void)
{
    int numerator, denominator, result;
    cout << "Enter the numerator and the denominator: ";
    cin >> numerator >> denominator;
    try
    {
        if (!denominator)
        {
            throw Exception();
        }
        result = numerator / denominator;
        cout << "The result after division is: " << result << '\n';
    }
    catch (const char *ex)
    {
        cout << "Exception occured: " << ex;
    }
    catch (Exception &exc)
    {
        cout << exc.what();
    }
    return 0;
}