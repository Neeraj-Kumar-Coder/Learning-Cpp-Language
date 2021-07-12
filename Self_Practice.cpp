#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class Array
{
private:
    int maxSize;
    int usedSize;
    int isSorted; // To make bubble sort adaptive
    friend void printArray(Array);
    friend void reverse(Array);
    friend class ArrayCalculator;

public:
    int *arr;

    Array(void)
    {
        maxSize = usedSize = 0;
        arr = NULL;
    }
    Array(int);

    void input(void);

    void sort(void)
    {
        for (int i = 0; i < usedSize - 1; i++)
        {
            isSorted = 1;
            for (int j = 0; j < usedSize - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    isSorted = 0;
                    swap(arr[j], arr[j + 1]);
                }
            }
            if (isSorted)
            {
                break;
            }
        }
    }
};

class ArrayCalculator
{
private:
    int sum;
    int product;

public:
    ArrayCalculator(void)
    {
        sum = 0;
        product = 1;
    }
    void add(Array object)
    {
        for (int i = 0; i < object.usedSize; i++)
        {
            sum += object.arr[i];
        }
    }
    void multiply(Array);
    void displayResult(void)
    {
        cout << "The sum is : " << sum << "\nThe product is : " << product << '\n';
    }
};

void ArrayCalculator::multiply(Array object)
{
    for (int i = 0; i < object.usedSize; i++)
    {
        product *= object.arr[i];
    }
}

void Array::input(void)
{
    cout << "Enter the number of elements you want to add: ";
    cin >> usedSize;
    for (int i = 0; i < usedSize; i++)
    {
        cout << "Enter the "
             << "element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

Array::Array(int size)
{
    maxSize = size;
    usedSize = 0;
    arr = new int[maxSize];
}

void printArray(Array object)
{
    for (int i = 0; i < object.usedSize; i++)
    {
        cout << object.arr[i] << ' ';
    }
    cout << '\n';
}

void reverse(Array object)
{
    for (int i = 0; i < object.usedSize / 2; i++)
    {
        swap(object.arr[i], object.arr[object.usedSize - 1 - i]);
    }
}

int main(void)
{
    Array a1;
    int sizeOfArray;
    cout << "Enter the size of the array you want to create: ";
    cin >> sizeOfArray;
    a1 = Array(sizeOfArray);
    a1.input();
    printArray(a1);
    a1.sort();
    printArray(a1);
    reverse(a1);
    printArray(a1);

    ArrayCalculator c1;
    c1.add(a1);
    c1.multiply(a1);
    c1.displayResult();
    return 0;
}