#include <iostream>

using namespace std;

int highestFactor(int number)
{
    int squareRoot = 2;
    while (squareRoot * squareRoot < number) // To find the number which is a square root or just greater than it
    {
        squareRoot++;
    }
    while (number % squareRoot) // To split into highest possible factors
    {
        squareRoot--;
    }
    return squareRoot > (number / squareRoot) ? squareRoot : (number / squareRoot);
}

int downToZero(int number)
{
    switch (number) // Base cases
    {
    case 0:
    case 1:
    case 2:
    case 3:
        return number;
    }

    int maxFactor = highestFactor(number);
    if (maxFactor == number) // For Prime Numbers
    {
        return 1 + downToZero(number - 1);
    }

    int partition_1 = 1 + downToZero(maxFactor);
    int partition_2 = 1 + downToZero(number - 1);
    return partition_1 < partition_2 ? partition_1 : partition_2;
}

int main(void)
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    cout << downToZero(number) << '\n';
    return 0;
}