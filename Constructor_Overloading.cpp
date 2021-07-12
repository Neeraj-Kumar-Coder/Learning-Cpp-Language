#include <iostream>

using namespace std;

class Point
{
private:
    int x, y, z;

public:
    Point(void)
    {
        x = y = z = 0;
    }
    Point(int x_coordinate)
    {
        x = x_coordinate;
        y = z = 0;
    }
    Point(int x_coordinate, int y_coordinate)
    {
        x = x_coordinate;
        y = y_coordinate;
        z = 0;
    }
    Point(int x_coordinate, int y_coordinate, int z_coordinate)
    {
        x = x_coordinate;
        y = y_coordinate;
        z = z_coordinate;
    }

    void printNumber(void)
    {
        cout << "The point's coordinate in the coordinate system is: (" << x << ", " << y << ", " << z << ")\n";
    }
};

int main(void)
{
    Point p1, p2(1), p3(1, 2), p4(1, 2, 3);
    p1.printNumber();
    p2.printNumber();
    p3.printNumber();
    p4.printNumber();
    return 0;
}