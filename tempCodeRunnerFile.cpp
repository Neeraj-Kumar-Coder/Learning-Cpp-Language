int main(void)
{
    Complex z1(3, 4);           // Implicit call
    Complex z2 = Complex(5, 6); // Explicit call
    z1.printNumber();
    z2.printNumber();
    return 0;
}