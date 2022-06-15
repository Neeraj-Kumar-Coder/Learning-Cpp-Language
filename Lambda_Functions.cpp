#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // Lambda Type 1
    []()
    {
        cout << "I am inside lambda 1\n";
    }(); // Calling also

    // Lambda Type 2
    auto adder_1 = [](int x, int y)
    { return x + y; };

    cout << adder_1(5, 3) << '\n';

    // Lambda Type 3
    function<int(int, int)> adder_2 = [](int x, int y)
    { return x + y; };

    cout << adder_2(5, 3) << '\n';
    return 0;
}