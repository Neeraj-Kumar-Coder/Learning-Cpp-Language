#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void printArray(int *, int);
vector<int> nearestGreaterToLeft(int *, int);
vector<int> nearestGreaterToRight(int *, int);
vector<int> nearestSmallerToLeft(int *, int);
vector<int> nearestSmallerToRight(int *, int);

int main(void)
{
    int numberOfElements;
    cout << "Enter the number of elements in that array: ";
    cin >> numberOfElements;
    int *array = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << "Enter the number: ";
        cin >> array[i];
    }

    cout << "Your Array is: ";
    printArray(array, numberOfElements);

    cout << "NearestGreaterToLeft: ";
    vector<int> answer1 = nearestGreaterToLeft(array, numberOfElements);
    for (auto i : answer1)
    {
        cout << i << ' ';
    }
    cout << '\n';

    cout << "NearestGreaterToRight: ";
    vector<int> answer2 = nearestGreaterToRight(array, numberOfElements);
    for (auto i : answer2)
    {
        cout << i << ' ';
    }
    cout << '\n';

    cout << "NearestSmallerToLeft: ";
    vector<int> answer3 = nearestSmallerToLeft(array, numberOfElements);
    for (auto i : answer3)
    {
        cout << i << ' ';
    }
    cout << '\n';

    cout << "NearestSmallerToRight: ";
    vector<int> answer4 = nearestSmallerToRight(array, numberOfElements);
    for (auto i : answer4)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}

void printArray(int *array, int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << array[i] << ' ';
    }
    cout << '\n';
}

vector<int> nearestGreaterToRight(int *array, int numberOfElements)
{
    stack<int> rightArrayStack;
    vector<int> answerArray;
    int i = numberOfElements - 1;
    while (i >= 0)
    {
        if (rightArrayStack.empty()) // Processed
        {
            answerArray.push_back(-1);
            rightArrayStack.push(array[i]);
            i--;
        }
        else if (rightArrayStack.top() <= array[i]) // Not Processed
        {
            rightArrayStack.pop();
        }
        else // Processed
        {
            answerArray.push_back(rightArrayStack.top());
            rightArrayStack.push(array[i]);
            i--;
        }
    }
    reverse(answerArray.begin(), answerArray.end());
    return answerArray;
}

vector<int> nearestSmallerToRight(int *array, int numberOfElements)
{
    stack<int> rightArrayStack;
    vector<int> answerArray;
    int i = numberOfElements - 1;
    while (i >= 0)
    {
        if (rightArrayStack.empty()) // Processed
        {
            answerArray.push_back(-1);
            rightArrayStack.push(array[i]);
            i--;
        }
        else if (rightArrayStack.top() >= array[i]) // Not Processed
        {
            rightArrayStack.pop();
        }
        else // Processed
        {
            answerArray.push_back(rightArrayStack.top());
            rightArrayStack.push(array[i]);
            i--;
        }
    }
    reverse(answerArray.begin(), answerArray.end());
    return answerArray;
}

vector<int> nearestGreaterToLeft(int *array, int numberOfElements)
{
    stack<int> leftArrayStack;
    vector<int> answerArray;
    int i = 0;
    while (i < numberOfElements)
    {
        if (leftArrayStack.empty()) // Processed
        {
            answerArray.push_back(-1);
            leftArrayStack.push(array[i]);
            i++;
        }
        else if (leftArrayStack.top() <= array[i]) // Not Processed
        {
            leftArrayStack.pop();
        }
        else // Processed
        {
            answerArray.push_back(leftArrayStack.top());
            leftArrayStack.push(array[i]);
            i++;
        }
    }
    return answerArray;
}

vector<int> nearestSmallerToLeft(int *array, int numberOfElements)
{
    stack<int> leftArrayStack;
    vector<int> answerArray;
    int i = 0;
    while (i < numberOfElements)
    {
        if (leftArrayStack.empty()) // Processed
        {
            answerArray.push_back(-1);
            leftArrayStack.push(array[i]);
            i++;
        }
        else if (leftArrayStack.top() >= array[i]) // Not Processed
        {
            leftArrayStack.pop();
        }
        else // Processed
        {
            answerArray.push_back(leftArrayStack.top());
            leftArrayStack.push(array[i]);
            i++;
        }
    }
    return answerArray;
}