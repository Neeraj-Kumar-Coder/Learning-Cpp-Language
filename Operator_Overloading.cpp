#include <bits/stdc++.h>

using namespace std;

class Master
{
private:
    int value;

public:
    // Default constructor
    Master(void) : value(0) {}

    // Parameterized constructor
    Master(const int value) : value(value) {}

    // // Deleted the compiler provided copy constructor to disable copying of objects
    // Master(Master &obj) = delete;

    // Overloading the prefix increment operator
    Master operator++(void)
    {
        this->value++;
        return *this;
    }

    // Overloading the postfix increment operator
    Master operator++(int dummy)
    {
        int temp = this->value;
        this->value++;
        return temp;
    }

    // Disabled the new operator for restricting dynamic memory allocation
    void *operator new(size_t size) {}

    // Disabled the new[] operator for restricting dynamic memory allocation
    void *operator new[](size_t size) {}

    // // Deleted the compiler provided overloaded version of = operator
    // Master operator=(Master &obj) = delete;

    // Defining the output format by overloading operator<< and making it a friend to allow access of private data
    friend ostream &operator<<(ostream &, Master &);
};

ostream &operator<<(ostream &out, Master &obj)
{
    out << obj.value << '\n';
    return out;
}

// Overloaded operator<< for printing any vector beautifully
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    out << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
            out << ", ";
        out << *it;
    }
    out << "]";
    return out;
}

int main(void)
{
    Master obj1(99), obj2;
    cout << obj1 << obj2;

    obj2 = obj1;
    ++obj2;
    obj2++;
    cout << obj2;

    vector<int> arr;
    for (int i = 0; i < 10; i++)
        arr.push_back(i);

    cout << arr;
    return 0;
}