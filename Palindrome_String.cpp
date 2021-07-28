#include <iostream>

using namespace std;

// Recursive
bool isPalindrome(string str, int low, int high)
{
    if (low < high)
    {
        if (str[low] == str[high])
        {
            return isPalindrome(str, low + 1, high - 1);
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Iterative
bool isPalindromeIterative(string str)
{
    int low = 0, high = str.length() - 1;
    while (low < high)
    {
        if (str[low] != str[high])
        {
            return false;
        }
        low += 1;
        high -= 1;
    }
    return true;
}

int main(void)
{
    string tester;
    cout << "Enter the string you want to check for palindrome: ";
    cin >> tester;
    int length = tester.length();
    if (isPalindrome(tester, 0, length - 1))
    {
        cout << "The given string is a Palindrome\n";
    }
    else
    {
        cout << "The given string is NOT a Palindrome\n";
    }
    if (isPalindromeIterative(tester))
    {
        cout << "The given string is a Palindrome\n";
    }
    else
    {
        cout << "The given string is NOT a Palindrome\n";
    }
    return 0;
}