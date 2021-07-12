#include <iostream>

using namespace std;

class Student
{
protected:
    string name;
    int roll_number;

public:
    void set_name(string);
    void set_roll_number(int);
    void display_roll_number(void);
    void display_name(void);
};

void Student::set_name(string nameOfStudent)
{
    name = nameOfStudent;
}

void Student::set_roll_number(int rollNumberOfStudent)
{
    roll_number = rollNumberOfStudent;
}

void Student::display_roll_number(void)
{
    cout << "The roll number of the student is: " << roll_number << '\n';
}

void Student::display_name(void)
{
    cout << "The name of the student is: " << name << '\n';
}

class Marks : public Student
{
protected:
    float maths;
    float science;

public:
    void set_marks(float, float);
    void display_marks(void);
};

void Marks::set_marks(float marksInMaths, float marksInScience)
{
    maths = marksInMaths;
    science = marksInScience;
}

void Marks::display_marks(void)
{
    cout << "Marks in maths: " << maths << "\nMarks in science: " << science << '\n';
}

class Result : public Marks
{
public:
    void display_result(void);
};

void Result::display_result(void)
{
    display_name();
    display_roll_number();
    display_marks();
    cout << "The percentage obtained is: " << (maths + science) / 2.0 << "%\n";
}

int main(void)
{
    Result Neeraj;
    Neeraj.set_name("Neeraj Kumar");
    Neeraj.set_roll_number(9);
    Neeraj.set_marks(95, 98);
    Neeraj.display_result();
    return 0;
}