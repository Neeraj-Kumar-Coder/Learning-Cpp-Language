#include <iostream>

using namespace std;

template <class type>
class Sample
{
private:
    type a;

public:
    Sample(type key) { a = key; }
    void display(void);
};

template <class type>
void Sample<type>::display(void)
{
    cout << "The value of a is: " << a << '\n';
}

template <class type1, class type2> // Template with multiple arguments
class SampleM
{
private:
    type1 var1;
    type2 var2;

public:
    SampleM(type1 a, type2 b) { var1 = a, var2 = b; }
    void display(void)
    {
        cout << "The values are: " << var1 << ' ' << var2 << '\n';
    }
};

void greet(int a) // Overloaded using the templatized function
{
    cout << "Good night " << a << '\n';
}

template <class type> // Function template
void greet(type a)    // Templatized function (overloaded)
{
    cout << "Good Morning " << a << '\n';
}

int main(void)
{
    Sample<int> object(5);
    object.display();

    greet(7);
    greet('7');
    SampleM<int, char> object1(4, 'z');
    object1.display();
    return 0;
}