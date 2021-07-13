#include <iostream>
#include <fstream>
/*
The useful classes for file I/O is:
1. fstreambase
2. ifstream -- derived from the fstreambase class (used for reading from the file)
3. ofstream -- derived from the fstreambase class (writing for reading to the file)
*/
using namespace std;

int main(void)
{
    // For writing to a file
    string str = "Neeraj Kumar";
    ofstream out("File.txt"); // File opened using constructor

    // ofstream out1;
    // out1.open("File.txt") // File opened using memeber function open()
    out << str;
    // or
    out << "This is also a correct way to write to the file"; // It will append to the file

    // For reading from a file
    string str1;
    ifstream in("File1.txt"); // File opened using constructor
    getline(in, str1);        // This will read until a newline is encountered
    // in>>str1; // This will read until a white space is encountered
    cout << "The content read was: " << str1;
    out.close();
    in.seekg(0, ios::beg); // reset the file pointer to the start of the stream

    while (!in.eof()) // It will read line by line till the end of file
    {
        getline(in, str1);
        cout << str1 << '\n';
    }
    in.close();
    // cout << "\nThe size of the string data type is : " << sizeof(str);
    return 0;
}