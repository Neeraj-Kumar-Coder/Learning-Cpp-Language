#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(void)
{
    int vertex, edges, key1, key2;
    cout << "Enter the number of vertices: ";
    cin >> vertex;
    cout << "Enter the number of edges: ";
    cin >> edges;
    vector<vector<int>> graph(vertex);

    while (edges--)
    {
        cout << "Enter the directed edge (a->b): ";
        cin >> key1 >> key2;
        if (key1 >= 0 && key2 >= 0 && key1 < vertex && key2 < vertex)
        {
            graph[key1].push_back(key2);
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
    queue<int> indexQueue;
    bool isVisited[vertex] = {false};
    cout << "BFS: ";
    for (int i = 0; i < vertex; i++)
    {
        if (!isVisited[i])
        {
            cout << i << ' ';
            isVisited[i] = true;
            indexQueue.push(i);
            while (!indexQueue.empty())
            {
                key1 = indexQueue.front();
                indexQueue.pop();
                for (auto &&j : graph[key1])
                {
                    if (!isVisited[j])
                    {
                        cout << j << ' ';
                        isVisited[j] = true;
                        indexQueue.push(j);
                    }
                }
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
    cout << "DFS: ";
    for (int i = 0; i < vertex; i++)
    {
        if (!isVisited[i])
        {
            cout << i << ' ';
            isVisited[i] = true;
            indexStack.push(i);
            while (!indexStack.empty())
            {
                key2 = indexStack.top();
                indexStack.pop();
                for (int j = 0; j < (int)graph[key2].size(); j++)
                {
                    if (!isVisited[graph[key2][j]])
                    {
                        cout << graph[key2][j] << ' ';
                        isVisited[graph[key2][j]] = true;
                        indexStack.push(key2);
                        key2 = graph[key2][j];
                        j = -1;
                    }
                }
            }
        }
    }
    cout << '\n';

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

    for (int i = 0; i < vertex; i++)
    {
        if (flag[i] == -1)
        {
            indexStack.push(i);
            flag[i] = 0;
            while (!indexStack.empty())
            {
                key2 = indexStack.top();
                indexStack.pop();
                flag[key2] = 1;
                for (int j = 0; j < (int)graph[key2].size(); j++)
                {
                    if (flag[graph[key2][j]] == -1)
                    {
                        flag[graph[key2][j]] = 1;
                        indexStack.push(key2);
                        flag[key2] = 0;
                        key2 = graph[key2][j];
                        j = -1;
                    }
                    else if (flag[graph[key2][j]] == 0)
                    {
                        cout << "Cycle Detected!\n";
                        goto skip;
                    }
                    else if (key2 == graph[key2][j])
                    {
                        cout << "Self loop detected!\n";
                    }
                }
            }
        }
    }
    cout << "No cycle detected!\n";
skip:
    return 0;
}