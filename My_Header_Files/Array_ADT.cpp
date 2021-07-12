#ifndef ARRAY_ADT
#define ARRAY_ADT
template <class type>
class Array
{
private:
    type *arr;
    int totalSize;
    int usedSize;

protected:
    void merge(int low, int mid, int high)
    {
        type *temp = new type[high - low + 1];
        int index1 = low, index2 = mid + 1, index3 = 0;
        while (index1 <= mid && index2 <= high)
        {
            if (arr[index1] < arr[index2])
            {
                temp[index3++] = arr[index1++];
            }
            else
            {
                temp[index3++] = arr[index2++];
            }
        }
        while (index1 <= mid)
        {
            temp[index3++] = arr[index1++];
        }
        while (index2 <= high)
        {
            temp[index3++] = arr[index2++];
        }
        for (int i = low, j = 0; i <= high; i++, j++)
        {
            arr[i] = temp[j];
        }
        delete[] temp;
    }
    void swap(type &a, type &b)
    {
        type temp = a;
        a = b;
        b = temp;
    }

public:
    Array(int size)
    {
        arr = new type[size];
        totalSize = size;
        usedSize = 0;
    }
    void input(void)
    {
        std::cout << "Enter the number of elements you want to add: ";
        std::cin >> usedSize;
        for (int i = 0; i < usedSize; i++)
        {
            std::cout << "Enter the element " << i + 1 << ": ";
            std::cin >> arr[i];
        }
    }
    void append(type key)
    {
        arr[usedSize++] = key;
    }
    int search(type key)
    {
        int index = 0;
        while (index < usedSize && arr[index++] != key)
            ;
        if (index < usedSize)
        {
            return index - 1;
        }
        else
        {
            return -1;
        }
    }
    void deleteKey(type key)
    {
        int index = search(key);
        if (index != -1)
        {
            for (int i = index + 1; i < usedSize; i++)
            {
                arr[i - 1] = arr[i];
            }
            usedSize--;
        }
        else
        {
            std::cout << "Invalid key!\n";
        }
    }
    void reverse(void)
    {
        for (int i = 0; i < usedSize / 2; i++)
        {
            swap(arr[i], arr[usedSize - 1 - i]);
        }
    }
    void sort()
    {
        sort(0, usedSize - 1);
    }
    void sort(int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            sort(low, mid);
            sort(mid + 1, high);
            merge(low, mid, high);
        }
    }
    void printArray(void)
    {
        for (int i = 0; i < usedSize; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }
};
#endif