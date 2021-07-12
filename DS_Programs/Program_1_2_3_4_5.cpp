#include <iostream>

using namespace std;

class Array
{
private:
    int maxSize;
    int usedSize;
    int *arr;

public:
    Array(int);
    void input(void);
    void sort(void);
    void mean(void);
    void median(void);
    void linearSearch(int);
    void binarySearch(int);
    void display(void);
};

Array::Array(int size)
{
    arr = new int[size];
    maxSize = size;
    usedSize = 0;
}

void Array::input(void)
{
    cout << "Enter the number of elements you want to add to the array: ";
    cin >> usedSize;
    for (int i = 0; i < usedSize; i++)
    {
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void Array::sort(void)
{
    int temp;
    for (int i = 0; i < usedSize - 1; i++)
    {
        for (int j = 0; j < usedSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Array::mean(void)
{
    int sum = 0;
    for (int i = 0; i < usedSize; i++)
    {
        sum += arr[i];
    }
    cout << "The mean of the array is: " << sum / usedSize << '\n';
}

void Array::median(void)
{
    sort();
    if (!(usedSize % 2))
    {
        cout << "The median of the sequence is: " << (arr[usedSize / 2] + arr[usedSize / 2 + 1]) / 2 << '\n';
    }
    else
    {
        cout << "The median of the sequence is: " << arr[usedSize / 2] / 2 << '\n';
    }
}

void Array::linearSearch(int key)
{
    for (int i = 0; i < usedSize; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element " << key << " is present in the array!\n";
            return;
        }
    }
    cout << "Element " << key << " is NOT present in the array!\n";
}

void Array::binarySearch(int key)
{
    int low, high, mid;
    low = 0;
    high = usedSize - 1;
    while (low <= high)
    {
        if (arr[low] == key || arr[high] == key)
        {
            cout << "Element " << key << " is present in the array!\n";
            return;
        }
        mid = (low + high) / 2;
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            cout << "Element " << key << " is present in the array!\n";
            return;
        }
    }
    cout << "Element " << key << " is NOT present in the array!\n";
}

void Array::display(void)
{
    for (int i = 0; i < usedSize; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main(void)
{
    Array a(50);
    a.input();
    a.display();
    a.sort();
    a.display();
    a.linearSearch(5);
    a.binarySearch(5);
    return 0;
}