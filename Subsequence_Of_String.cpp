#include <iostream>

using namespace std;

void subSequence(string str, int index = 0, string current = "")
{
    if (index == str.length())
    {
        cout << ">>" << current << "<<" << '\n';
        return;
    }
    subSequence(str, index + 1, current + str[index]);
    subSequence(str, index + 1, current);
}

int main(void)
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    cout << "The sub sequence of this string are\n";
    subSequence(str);
    return 0;
}