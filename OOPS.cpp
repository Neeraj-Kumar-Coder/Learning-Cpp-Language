#include <iostream>

using namespace std;

class Employee
{
private:
    int salary, age;

public:
    int workingDays;
    void setData(int, int, int);
    void printData(void)
    {
        cout << "Salary: " << salary << "\nAge: " << age << "\nWorking Days: " << workingDays << '\n';
    }
};

void Employee::setData(int amount, int number, int days)
{
    salary = amount;
    age = number;
    workingDays = days;
}

int main(void)
{
    Employee Neeraj;
    Neeraj.setData(50000, 20, 5);
    Neeraj.printData();

    // cout << Neeraj.salary; // This will throw an error as salary is a private variable \
    and can be accessed by the methods inside the class only

    return 0;
}