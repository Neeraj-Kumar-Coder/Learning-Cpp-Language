#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void)
{
    // Taking the graph as input
    int vertex, edges, key1, key2;
    cout << "Enter the number of vertices: ";
    cin >> vertex;
    cout << "Enter the number of edges: ";
    cin >> edges;
    vector<vector<int>> graph(vertex);
    while (edges--)
    {
        cout << "Enter the edge: ";
        cin >> key1 >> key2;
        if (key1 >= 0 && key2 >= 0 && key1 < vertex && key2 < vertex)
        {
            graph[key1].push_back(key2);
            graph[key2].push_back(key1);
        }
    }
    
    cout << "\nThe Adjacency List Of The Graph Is:\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << i << ": ";
        for (auto j : graph[i])
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    // BFS of the graph
    bool isVisited[vertex] = {false};
    isVisited[key1] = true;
    queue<int> indexQueue;

    cout << "Enter the intial vertex for BFS: ";
    cin >> key1;

    cout << "BFS: ";
    cout << key1 << ' ';
    indexQueue.push(key1);
    while (!indexQueue.empty())
    {
        key2 = indexQueue.front();
        indexQueue.pop();
        for (auto &&i : graph[key2])
        {
            if (!isVisited[i])
            {
                cout << i << ' ';
                isVisited[i] = true;
                indexQueue.push(i);
            }
        }
    }
    cout << '\n';

    // Resetting isVisited array
    for (auto &&i : isVisited)
    {
        i = false;
    }

    // DFS of the graph
    stack<int> indexStack;

    cout << "Enter the intial vertex for DFS: ";
    cin >> key2;

    cout << "DFS: ";
    cout << key2 << ' ';
    isVisited[key2] = true;
    indexStack.push(key2);
    while (!indexStack.empty())
    {
        key2 = indexStack.top();
        indexStack.pop();
        for (int i = 0; i < (int)graph[key2].size(); i++)
        {
            if (!isVisited[graph[key2][i]])
            {
                cout << graph[key2][i] << ' ';
                isVisited[graph[key2][i]] = true;
                indexStack.push(key2);
                key2 = graph[key2][i];
                i = -1;
            }
        }
    }
    cout << '\n';
    return 0;
}