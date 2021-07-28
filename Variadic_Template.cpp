/*
    The variadic function works as follows:
    1) The statement : print(23, "Hello", 56.8f) is evaluated in the following manner
        1.1) cout << 23 << ' ';
            print("Hello", 56.8f);
        
        1.2) cout << "Hello" << ' ';
            print(56.8f);

        1.3) cout << 56.8f << ' ';
            print();

    2) At the end it searches for the empty parameter overload of the function. In this case it has one!
        2.1) DOES NOTHING (IN THIS CASE, AS THE OVERLOAD DOES NOTHING)
*/

#include <iostream>

using namespace std;

void print(void) {} // This will be called for zero number of parameters

template <typename typeBase, typename... extraType>
void print(typeBase paramBase, extraType... extraParam)
{
    cout << paramBase << ' ';
    print(extraParam...);
}

int main(void)
{
    print(23, "Hello", 56.8f);
    return 0;
}