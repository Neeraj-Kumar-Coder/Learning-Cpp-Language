#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int vertices;
    vector<vector<int>> edges;

public:
    vector<int> res;

    Solution(int x)
    {
        vertices = x;
    }

    void Addedges(int x, int y)
    {
        edges.push_back({x, y});
    }

    bool Utility(vector<int> graph[], vector<int> &visited, int index, vector<int> &x)
    {
        if (x[index] == 1)
            return false;

        else if (visited[index] == 1)
            return true;

        visited[index] = 1;
        x[index] = 1;

        for (auto i : graph[index])
        {
            bool temp = Utility(graph, visited, i, x);
            if (!temp)
                return false;
        }
        res.push_back(index);
        x[index] = 0;
        return true;
    }

    vector<int> TopologicalSort(int vertices)
    {
        vector<int> graph[vertices];
        for (auto i : edges)
            graph[i[0]].push_back(i[1]);

        vector<int> visited(vertices, 0);
        vector<int> x(vertices, 0);
        for (int i = 0; i < vertices; i++)
        {
            if (visited[i] == 0)
            {
                bool temp = Utility(graph, visited, i, x);
                if (!temp)
                {
                    cout << "There is a cycle in this graph";
                    exit(0);
                }
            }
        }
        return res;
    }
};

int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    Solution obj(vertices);
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges: ";
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a >= vertices || b >= vertices)
        {
            cout << "Enter a valid value to the vertex";
            return 0;
        }

        obj.Addedges(a, b);
    }

    cout << "The topological sort looks like: ";
    for (int x : obj.TopologicalSort(vertices))
        cout << x << " ";

    return 0;
}