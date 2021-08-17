#include <iostream>

using namespace std;

int main(void)
{
    // If we generate random number with rand() without calling srand() then each time we run the program
    // It will generate the random number in the same sequence
    for (int i = 0; i < 5; i++)
    {
        cout << rand() << ' ';
    }
    cout << '\n';

    // Now using srand()
    // Using current time as a seed for random number generation
    // If srand() is not called, the rand() seed is set as if srand(1) were called at program start.
    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        cout << rand() << ' ';
    }
    cout << '\n';

    // For random numbers in a range [lowerBound, upperBound]
    int lowerBound = 5, upperBound = 50;

    for (int i = 0; i < 5; i++)
    {
        cout << (rand() % (upperBound - lowerBound + 1) + lowerBound) << ' ';
    }
    cout << '\n';
    return 0;
}