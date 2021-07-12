#include <iostream>

using namespace std;

class A
{
    int a;

public:
    A *setData(int a)
    {
        this->a = a;
        return this;
    }
    void getData(void)
    {
        cout << "The value of a is : " << a << '\n';
    }
};

int main(void)
{
    A *obj = new A;
    obj->setData(5)->getData();
    return 0;
}