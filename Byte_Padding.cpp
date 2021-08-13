// To reduce padding we should declare structure member in descending order of the size
#include <iostream>
#include <iomanip>

using namespace std;

struct Byte_Padding
{
    int a;
    long long int c;
    long double b;
};

int main(void)
{
    cout << sizeof(Byte_Padding) << '\n';
    return 0;
}