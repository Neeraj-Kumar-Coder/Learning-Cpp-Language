#include <iostream>

using namespace std;

int main()
{
    int arr[] = {25, 36, 21, 21, 65, 35, 65, 35};
    int length = sizeof(arr) / sizeof(int);

    int onlyNonRepeatingElement = 0;

    for (int i = 0; i < length; i++)
    {
        onlyNonRepeatingElement ^= arr[i];
    }

    // cout << "The only non repeating element is: " << onlyNonRepeatingElement << '\n';

    int temp = onlyNonRepeatingElement;
    unsigned int mask = 1;

    while (!(temp & mask))
    {
        mask <<= 1;
    }

    for (int i = 0; i < length; i++)
    {
        if ((arr[i] & mask))
        {
            temp ^= arr[i];
        }
    }
    cout << "The two non repeatin elements are: " << temp << ' ' << (temp ^ onlyNonRepeatingElement) << '\n';
    return 0;
}