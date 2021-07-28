#include <iostream>
#include <stdexcept>

using namespace std;

int main(void)
{
    try
    {
        unsigned long long i = 0;
        for (;;)
        {
            int *ptr = new int[++i];
        }
    }
    catch (bad_alloc &exc)
    {
        cout << "Exception Occured: " << exc.what() << '\n';
    }
    return 0;
}