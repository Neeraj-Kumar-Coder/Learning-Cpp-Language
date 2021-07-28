#include <iostream>

using namespace std;

// Enumeration class
enum class Rainbow
{
    violet,
    indigo,
    blue,
    green,
    yellow,
    orange,
    red
};

// Normal Enumeration
enum Color
{
    red
};

// Normal Enumeration
enum Equa
{
    star
};

int main(void)
{
    Rainbow obj = Rainbow::blue;

    if (obj == Rainbow::blue)
    {
        cout << "It's the same\n";
    }
    else
    {
        cout << "That's different\n";
    }
    Color obj1 = red;
    Equa obj2 = star;
    if (obj1 == obj2) // Warning: comparison between 'enum Color' and 'enum Equa'
    {
        cout << "They are same\n";
    }
    else
    {
        cout << "They are different\n";
    }
    return 0;
}