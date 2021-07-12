#include <iostream>

using namespace std;

class Base
{
    int data1;

public:
    int data2;
    void setData(void);
    int getData1(void);
    int getData2(void);
};

void Base::setData(void)
{
    data1 = 10;
    data2 = 20;
}

int Base::getData1(void)
{
    return data1;
}

int Base::getData2(void)
{
    return data2;
}

class Derived : public Base
{
    int data3;

public:
    int data4;
    void process(void);
    void display(void);
};

void Derived::process(void)
{
    data3 = getData1() * data2;
    data4 = data3 / 10;
}

void Derived::display(void)
{
    cout << "Data 1 = " << getData1() << "\nData 2 = " << data2 << "\nData 3 = " << data3 << "\nData 4 = " << data4 << '\n';
}

int main(void)
{
    Derived d1;
    d1.setData();
    d1.process();
    d1.display();
    return 0;
}