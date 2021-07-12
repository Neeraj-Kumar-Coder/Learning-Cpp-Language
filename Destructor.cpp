#include <iostream>

using namespace std;

class Template
{
public:
    Template(void) // Called when the object is created
    {
        cout << "Constructor is run\n";
    }

    ~Template(void) // Called when the object is destoryed
    {
        cout << "Destructor is run\n";
    }
};

int main(void)
{
    cout << "Inside main\n";
    Template object;
    return 0;
}