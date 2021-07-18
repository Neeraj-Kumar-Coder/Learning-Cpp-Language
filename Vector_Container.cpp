#include <iostream>
#include <vector>

using namespace std;

template <class type>
void displayVector(vector<type> &v)
{
    int length = v.size();
    cout << "The vector is: ";
    for (int i = 0; i < length; i++)
    {
        cout << v.at(i) << ' ';
    }
    cout << '\n';
}

template <class type>
void displayUsingIterator(vector<type> &v)
{
    cout << "The vector is : ";
    vector<int>::iterator it = v.begin(); // Iterator for vector storing integers (treated just like pointers)
    while (it != v.end())
    {
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
}

int main(void)
{
    vector<int> vec1; // using empty container constructor
    cout << "\nThe size of vec1 is : " << vec1.size() << '\n';
    cout << "The size of vector data type is : " << sizeof(vec1) << '\n';
    displayVector(vec1);
    displayUsingIterator(vec1);

    vector<int> vec2(10); // using single argument constructor (same as vec2(10, 0))
    cout << "\nThe size of vec2 is : " << vec2.size() << '\n';
    cout << "The size of vector data type is : " << sizeof(vec2) << '\n';
    displayVector(vec2);
    displayUsingIterator(vec2);

    vector<int> vec3(10, 9); // using fill constructor
    cout << "\nThe size of vec3 is : " << vec3.size() << '\n';
    cout << "The size of vector data type is : " << sizeof(vec3) << '\n';
    displayVector(vec3);
    displayUsingIterator(vec3);

    vector<int> vec4(vec3); // using copy constructor
    cout << "\nThe size of vec4 is : " << vec4.size() << '\n';
    cout << "The size of vector data type is : " << sizeof(vec4) << '\n';
    displayVector(vec4);
    displayUsingIterator(vec4);

    vector<int> vec5(vec4.begin(), vec4.end()); // iterating through vec4
    cout << "\nThe size of vec5 is : " << vec5.size() << '\n';
    cout << "The size of vector data type is : " << sizeof(vec5) << '\n';
    displayVector(vec5);
    displayUsingIterator(vec5);

    vector<int> vec6 = vec5; // using operator =
    cout << "\nThe size of vec6 is : " << vec6.size() << '\n';
    cout << "The size of vector data type is : " << sizeof(vec6) << '\n';
    displayVector(vec6);
    displayUsingIterator(vec6);

    // *********************************************************************

    vector<int> vec7;
    for (int i = 0; i < 5; i++)
    {
        vec7.push_back(i);
    }

    // It is a reverse iterator which when incremented, iterates the vector backwards
    vector<int>::reverse_iterator rit = vec7.rbegin();
    cout << "The value is: " << *rit << '\n';
    cout << "The value is: " << *(rit + 1) << '\n';
    cout << "The value is: " << *(rit + 2) << '\n';

    vec6.clear(); // It clears the vector
    displayVector(vec6);
    cout << "The size of the vector after clear operation on vec6 is : " << vec6.size() << '\n';
    cout << "The maximum size of the vector can be : " << vec6.max_size() << '\n';

    // *********************************************************************

    vector<int> vec8(100);
    cout << "The capacity of vec8 is : " << vec8.capacity() << '\n';
    cout << "The size of vec8 is : " << vec8.size() << '\n';
    vec8.resize(10);
    cout << "The capacity of vec8 is : " << vec8.capacity() << '\n';
    cout << "The size of vec8 is : " << vec8.size() << '\n';
    vec8.shrink_to_fit();
    cout << "The capacity of vec8 is : " << vec8.capacity() << '\n';
    cout << "The size of vec8 is : " << vec8.size() << '\n';
    return 0;
}