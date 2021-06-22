#include <iostream>
#include <string>

using namespace std;

class Binary
{
    string number;

public:
    void read(void);
    void onesCompliment(void);
    void displayNumber(void);

private:
    void checkBinary(void);
};

void Binary::read(void)
{
    cout << "Enter your binary number: ";
    cin >> number;
    checkBinary(); // Nested member function
}

void Binary::checkBinary(void)
{
    for (auto i : number)
    {
        if (i != '0' && i != '1')
        {
            cout << "Incorrect Binary Format!!!\n";
            exit(EXIT_FAILURE);
        }
    }
}

void Binary::displayNumber(void)
{
    cout << "Your Binary number is: " << number << '\n';
}

void Binary::onesCompliment(void)
{
    for (auto &i : number)
    {
        i = (i == '1') ? '0' : '1';
    }
}

int main(void)
{
    Binary member;
    member.read();
    member.displayNumber();
    member.onesCompliment();
    member.displayNumber();
    return 0;
}