#include <iostream>

using namespace std;

class Base
{
private:
    int pri;

protected:
    int pro;

public:
    int pub;
};

class PrivateDerived : private Base
{
    ;
};

class ProtectedDerived : protected Base
{
    ;
};

class PublicDerived : public Base
{
    ;
};

int main(void)
{
    PrivateDerived obj1;
    ProtectedDerived obj2;
    PublicDerived obj3;

    // obj1.pri = 10; // Not inherited
    // obj1.pro = 10; // Inherited as private
    // obj1.pub = 10; // Inherited as private

    // obj2.pri = 10; // Not inherited
    // obj2.pro = 10; // Inherited as protected
    // obj2.pub = 10; // Inherited as protected

    // obj3.pri = 10; // Not inherited
    // obj3.pro = 10; // Inherited as protected
    obj3.pub = 10; // Inherited as public
    return 0;
}