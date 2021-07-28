#include <iostream>
#include <stdexcept>

using namespace std;

int main(void)
{
    int numerator, denominator, quotient, remainder;
    cout << "Enter the value of numerator and denominator: ";
    cin >> numerator >> denominator;
    try
    {
        if (!numerator && !denominator)
        {
            throw logic_error("Logical Error: Indeterminate Form!\n");
        }
        else if (!denominator)
        {
            throw runtime_error("Math Error: Attemp to divide by zero!\n");
        }

        else if (numerator < 0 || denominator < 0)
        {
            throw invalid_argument("Invalid Arguments: Negative numbers not allowed!\n");
        }
        else
        {
            quotient = numerator / denominator;
            remainder = numerator % denominator;
            cout << "The result after division is:\n"
                 << "Quotient: " << quotient << "\nRemainder: " << remainder << '\n';
        }
    }
    catch (logic_error &exc)
    {
        cout << exc.what();
    }
    catch (runtime_error &exc)
    {
        cout << exc.what();
    }
    // catch (invalid_argument &exc) // We don't need this catch, as the invalid_argument is inherited from the logical error so it is catched by the first catch statement only
    // {
    //     cout << exc.what();
    // }
    catch (...)
    {
        cout << "Some Exception Occured!\n";
    }

    cout << "\nProgram Finished...\n";
    return 0;
}

/* 
Some other exceptions:

1. Vector exception (out of range):
-> catch(out_of_range &exc) { cout << exc.what() << '\n';}

2. Out of memory exception (for dynamic memory allocation using new)
-> catch(bad_alloc &exc) { cout << exc.what() << '\n';}
*/