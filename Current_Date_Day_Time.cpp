/*
Points to remember:

1. This program will give output different for different time zones as per the time in that time zone.
2. The Day, Date and Time in the output is independent of the system day, date and time.
   You can change your system date and time settings, but still the output will not be affected,
   and will give the correct information.
*/
#include <iostream>

using namespace std;

int main(void)
{
    time_t tt;
    tm *ti;
    time(&tt);
    ti = localtime(&tt);
    cout << asctime(ti) << '\n';
    return 0;
}