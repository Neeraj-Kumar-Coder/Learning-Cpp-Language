#include <iostream>

using namespace std;

class Bank
{
    int principle;
    int years;
    int returnValue;
    float interestRate;

public:
    Bank(void){}; // This empty constructor is needed to create empty objects
    Bank(int, int, float);
    Bank(int, int, int);

    void showAmount(void)
    {
        cout << "The principle amount is = " << principle << "\nInterest rate = " << interestRate << "\nTime period is = " << years << "\nFinal returning amount = " << returnValue << '\n';
    }
};

Bank::Bank(int p, int y, int r)
{
    principle = p;
    years = y;
    interestRate = r / 100.0f;
    returnValue = principle;

    for (int i = 0; i < years; i++)
    {
        returnValue += returnValue * interestRate;
    }
}

Bank::Bank(int p, int y, float r)
{
    principle = p;
    years = y;
    interestRate = r;
    returnValue = principle;

    for (int i = 0; i < years; i++)
    {
        returnValue += returnValue * interestRate;
    }
}

int main(void)
{
    Bank member1, member2;
    int p, y, rP;
    float rF;

    cout << "Enter p, y and rP: ";
    cin >> p >> y >> rP;

    member1 = Bank(p, y, rP);
    member1.showAmount();

    cout << "Enter p, y and rF: ";
    cin >> p >> y >> rF;

    member2 = Bank(p, y, rF);
    member2.showAmount();

    return 0;
}