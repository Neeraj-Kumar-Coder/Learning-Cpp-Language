#include <iostream>

using namespace std;

class AddNumber
{
    int number1, number2;
    friend int sum(AddNumber); // It gives sum() the rights to access and change the private members of the class

public:
    void getNumber(int value1, int value2)
    {
        number1 = value1;
        number2 = value2;
    }
};

int sum(AddNumber a)
{
    return a.number1 + a.number2;
}

int main(void)
{
    AddNumber member;
    member.getNumber(5, 7);
    cout << "The sum is: " << sum(member) << '\n';
    return 0;
}