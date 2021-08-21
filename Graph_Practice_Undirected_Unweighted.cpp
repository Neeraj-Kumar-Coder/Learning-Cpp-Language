#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

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
    queue<int> indexQueue;

    cout << "Enter the intial vertex for BFS: ";
    cin >> key1;

    cout << "BFS: ";
    cout << key1 << ' ';
    isVisited[key1] = true;
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

    // Resetting
    for (auto &&i : isVisited)
    {
        i = false;
    }
    while (!indexQueue.empty())
    {
        indexQueue.pop();
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
    while (!indexStack.empty())
    {
        indexStack.pop();
    }

    // Cyclic Detection
    /*
    flag:
    { -1, unvisited
    { 0, visited and in stack
    { 1, visited but not in stack
    */
    int flag[vertex];
    for (auto &&i : flag)
    {
        i = -1; // Marking every vertex unvisited
    }
    map<int, int> parentMap;

    key2 = 0;
    indexStack.push(key2);
    flag[key2] = 0;
    while (!indexStack.empty())
    {
        key2 = indexStack.top();
        indexStack.pop();
        flag[key2] = 1;
        for (int i = 0; i < (int)graph[key2].size(); i++)
        {
            if (flag[graph[key2][i]] == -1)
            {
                flag[graph[key2][i]] = 1;
                parentMap[graph[key2][i]] = key2;
                indexStack.push(key2);
                flag[key2] = 0;
                key2 = graph[key2][i];
                i = -1;
            }
            else if (flag[graph[key2][i]] == 0 && parentMap[key2] != graph[key2][i])
            {
                cout << "Cycle Detected!\n";
                goto skip;
            }
            else if (key2 == graph[key2][i])
            {
                cout << "Self loop detected!\n";
            }
        }
    }
    cout << "No Cycle Detected!\n";

skip:
    while (!indexStack.empty()) // Resetting everthing
    {
        indexStack.pop();
    }

    // Checking for bipartite graph
    /*
    color
    {-1, uncolored and unvisited
    { 0, red colored and visited
    { 1, black colored and visited
    */
    int color[vertex];
    for (auto &&i : color)
    {
        i = -1;
    }

    key1 = 0;
    color[key1] = 0;
    indexQueue.push(key1);
    while (!indexQueue.empty())
    {
        key1 = indexQueue.front();
        indexQueue.pop();
        for (int i = 0; i < (int)graph[key1].size(); i++)
        {
            if (color[graph[key1][i]] == -1)
            {
                color[graph[key1][i]] = color[key1] == 0 ? 1 : 0;
                indexQueue.push(graph[key1][i]);
            }
            else
            {
                int tempColor = color[graph[key1][i]] == 0 ? 1 : 0;
                if (tempColor != color[key1])
                {
                    cout << "Graph is not Bipartite!\n";
                    goto last;
                }
            }
        }
    }
    cout << "Graph is Bipartite!\n";
last:
    while (!indexQueue.empty())
    {
        indexQueue.pop();
    }
    return 0;
}