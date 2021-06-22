#include <iostream>

using namespace std;

class Test
{
    int Id;           // By default private
    static int count; // By default private (static data member)

public:
    void input(void)
    {
        cout << "Enter the id : ";
        cin >> Id;
        count++;
    }
    void printID(void);

    static void printCount(void) // This static function (or Method) only have access to static data members
    {
        cout << "Value of count is : " << count << '\n';
    }
};

int Test::count; // Declaration that static data member belongs to the class

void Test::printID(void) // It can access both static and non static data members
{
    cout << "The id is : " << Id << '\n'
         << "Count is : " << count << '\n';
}

int main(void)
{
    Test testMember;
    testMember.input();
    testMember.printID();

    testMember.input();
    testMember.printID();

    Test::printCount(); // Static member functions is called like this (i.e. by using scope resolution operator)
    return 0;
}