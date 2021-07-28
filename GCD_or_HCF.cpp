#include <iostream>

using namespace std;

int gcd(int, int);

int main(void)
{
    int a, b;
    cout << "Enter two numbers you want to find the HCF of: ";
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    return 0;
}

int gcd(int a, int b)
{
    if (!(a % b))
        return b;
    else
        return gcd(b, a % b);
}