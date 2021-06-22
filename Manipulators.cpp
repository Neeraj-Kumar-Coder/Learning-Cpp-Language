#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    int a = 1, b = 10, c = 1000;
    cout << setw(4) << a << '\n'
         << setw(4) << b << '\n'
         << setw(4) << c << '\n';
    return 0;
}