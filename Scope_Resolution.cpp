#include <iostream>

using namespace std;

int global = 10;

int main(void)
{
    int global = 19;
    cout << "The value of local variable is: " << global << "\n";
    cout << "The value of global variable is: " << ::global << "\n";
    return 0;
}