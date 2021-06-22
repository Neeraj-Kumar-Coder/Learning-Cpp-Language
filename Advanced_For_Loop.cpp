#include <iostream>

using namespace std;

int main(void)
{
    int arr[] = {1, 5, 9, 7, 5, 3, 6, 4, 8, 2};

    // for (auto &&i : arr) // This will change the original elements
    for (auto i : arr) // This will NOT change the original elements
    {
        i += 1;
        cout << i << " ";
    }

    printf("\n");

    for (auto &&j : arr)
    {
        cout << j << " ";
    }

    return 0;
}