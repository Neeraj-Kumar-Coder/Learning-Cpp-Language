#include <iostream>

using namespace std;

int main(void)
{
    int a;
    string b;

    cin >> a;

    // cin >> b; // agar ye use krenge string k input k liye, tb cin.ignore() is jroorat nahi (pata nahi kyu)

    cin.ignore();
    // fflush(stdin);
    getline(cin, b);
    cout << a << ' ' << b << '\n';
    return 0;
}