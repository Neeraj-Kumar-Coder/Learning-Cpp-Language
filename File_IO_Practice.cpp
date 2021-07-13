#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    ofstream fout; // an ofstream object to write to the file
    fout.open("File_IO_Practice.txt", ios::out);
    // ios::out --> opens the file for writing (default for ofstream object)
    fout << "This will be written to the file using the ofstream object\n";
    fout << "By, Neeraj Kumar";
    fout.close(); // To close the file as it is opened in the write mode restricting the read operation

    ifstream fin; // an ifstream object to read from the file
    fin.open("File_IO_Practice.txt", ios::in);
    // ios::in --> opens the file for reading (default for ifstream object)
    string store;

    cout << "The content read was: ";
    while (!fin.eof()) // Will continue to read word by word till the occurence of the eof(end of file) character
    {
        fin >> store;
        cout << store << ' ';
    }
    return 0;
}