#include <bits/stdc++.h>

#define console_log(...) recursive_printer(__VA_ARGS__)

using namespace std;

class Base
{
public:
    virtual ~Base(void) {}
};

class Derived : public Base
{
    ;
};

template <typename T>
ostream &operator<<(ostream &out, vector<T> &obj)
{
    cout << "[";
    for (auto it = obj.begin(); it != obj.end(); ++it)
    {
        if (it != obj.begin())
            cout << ", ";
        cout << *it;
    }
    cout << "]";
    return out;
}

template <int... values>
void printer(void)
{
    for (auto &&value : {values...})
    {
        cout << value << ' ';
    }
    cout << '\n';
}

void recursive_printer(void)
{
    cout << '\n';
}

template <typename T, typename... types>
void recursive_printer(T value, types... values)
{
    cout << value << ' ';
    recursive_printer(values...);
}

int main(void)
{
    Base *bptr = new Derived();
    if (Derived *dptr = dynamic_cast<Derived *>(bptr))
    {
        cout << "Base pointer is pointing to derived class!\n";
    }
    else
    {
        cout << "Base pointer is not pointing to derived class!\n";
    }

    printer<1, 2, 3, 4>();
    recursive_printer(1, 2, 3, "Hi I am neeraj", 55.33);

    float real = 12.334;
    int integer = static_cast<int>(real);
    console_log("The integer value is", integer, "of the real number", real);
    return 0;
}