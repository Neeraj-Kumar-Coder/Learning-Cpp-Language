#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    function<char(int)> getAlpha = [](int offset) -> char
    {
        return 'a' + offset;
    };

    cout << getAlpha(3) << '\n';
    return 0;
}