#include <iostream>

using namespace std;

class BaseClass
{
private:
    int var_base_private;

public:
    int var_base;
    void display(void)
    {
        cout << "The value of var_base is : " << var_base << '\n';
    }
};

class DerivedClass : public BaseClass
{
public:
    int var_derived;
    void display(void)
    {
        cout << "The value of var_base is : " << var_base << '\n';
        cout << "The value of var_derived is : " << var_derived << '\n';
    }
};

int main(void)
{
    BaseClass *BaseClassPointer = NULL;
    DerivedClass *DerivedClassPointer = NULL;

    // BaseClass BaseClassObject;
    DerivedClass DerivedClassObject;

    // LATE BINDING (CONCEPT OF POLYMORPHISM) [RUNTIME POLYMORPHISM]
    BaseClassPointer = &DerivedClassObject;
    BaseClassPointer->var_base = 95;
    BaseClassPointer->display();
    // BaseClassPointer->var_derived = 95; // Will throw an error
    // BaseClassPointer->display();

    DerivedClassPointer = &DerivedClassObject;
    DerivedClassPointer->var_derived = 900;
    DerivedClassPointer->display();
    return 0;
}