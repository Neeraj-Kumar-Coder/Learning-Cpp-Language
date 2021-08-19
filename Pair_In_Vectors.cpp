#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<pair<int, string>> pairVec;
    int key, numberOfKeys;
    string value;
    cout << "Enter the number of key value you want to push: ";
    cin >> numberOfKeys;
    while (numberOfKeys--)
    {
        cout << "Enter the pair (int, string): ";
        cin >> key;
        getline(cin, value);
        pairVec.push_back(make_pair(key, value));
        // pairVec.push_back({key, value}); // Alternative assignment
    }
    for (int i = 0; i < (int)pairVec.size(); i++)
    {
        cout << pairVec[i].first << ' ' << pairVec[i].second << '\n';
    }
    return 0;
}