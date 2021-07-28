#include <iostream>

using namespace std;

void swap(char &ch1, char &ch2)
{
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

void permutations(string source, int low, int high)
{
    if (low == high)
    {
        cout << source << '\n';
        return;
    }
    for (int i = low; i <= high; i++)
    {
        if (i == low || source[low] != source[i])
        {
            swap(source[low], source[i]);
            permutations(source, low + 1, high);
            swap(source[low], source[i]);
        }
    }
}

int main(void)
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    cout << "The permutations of the string is\n";
    permutations(str, 0, str.length() - 1);
    return 0;
}