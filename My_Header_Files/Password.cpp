#ifndef PASSWORD
#define PASSWORD
#include <iostream>
#include <conio.h>
bool setPassword(const char *passKey)
{
    std::string enteredPassKey;
    char tempChar;
    std::cout << "Enter the password: ";
    while ((tempChar = getch()) != '\r')
    {
        if (tempChar == '\b')
        {
            enteredPassKey.pop_back();
            std::cout << '\b' << ' ' << '\b';
        }
        else
        {
            enteredPassKey.push_back(tempChar);
            std::cout << '*';
        }
    }
    if (enteredPassKey == passKey)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif