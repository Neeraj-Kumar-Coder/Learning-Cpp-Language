// Also handles the case with all the negative elements
#include <iostream>

using namespace std;

int kadanesSum(int *arr, int length)
{
    int current = arr[0], maxSum = arr[0];
    for (int i = 1; i < length; i++)
    {
        current = arr[i] > current + arr[i] ? arr[i] : current + arr[i];
        if (maxSum < current)
        {
            maxSum = current;
        }
    }
    return maxSum;
}

int main(void)
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(int);
    cout << "The max sum subarray is: " << kadanesSum(arr, size) << '\n';
    return 0;
}