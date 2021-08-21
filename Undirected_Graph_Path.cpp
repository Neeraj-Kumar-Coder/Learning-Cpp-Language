#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> path; // Stores the path from source to destination

bool hasPath(vector<vector<int>> graph, int source, int destination, bool isVisited[])
{
    if (source == destination)
    {
        return true;
    }
    isVisited[source] = true;

    for (int i = 0; i < (int)graph[source].size(); i++)
    {
        if (!isVisited[graph[source][i]])
        {
            path.push_back(graph[source][i]);
            bool hasPathFromNeighbour = hasPath(graph, graph[source][i], destination, isVisited);
            if (hasPathFromNeighbour)
            {
                return true;
            }
            path.pop_back();
        }
    }
    return false;
}

void getAllPaths(vector<vector<int>> graph, int source, int destination, bool isVisited[], string pathTillNow)
{
    if (source == destination)
    {
        cout << pathTillNow << '\n';
        return;
    }
    isVisited[source] = true;

    for (int i = 0; i < (int)graph[source].size(); i++)
    {
        if (!isVisited[graph[source][i]])
        {
            getAllPaths(graph, graph[source][i], destination, isVisited, pathTillNow + '-' + to_string(graph[source][i]));
        }
    }
    isVisited[source] = false;
}

int main(void)
{
    int vertex, edges, vertex_1, vertex_2;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex);
    while (edges--)
    {
        cout << "Enter the edge: ";
        cin >> vertex_1 >> vertex_2;
        graph[vertex_1].push_back(vertex_2);
        graph[vertex_2].push_back(vertex_1);
    }
    bool isVisited[vertex] = {false};

    cout << "Enter the source vertex and the destination vertex: ";
    cin >> vertex_1 >> vertex_2;
    path.push_back(vertex_1);

    if (hasPath(graph, vertex_1, vertex_2, isVisited))
    {
        cout << "There is the path between the vertices " << vertex_1 << " & " << vertex_2 << ": ";
        for (vector<int>::iterator it = path.begin(); it != path.end(); it++)
        {
            cout << *it << ' ';
        }
        cout << '\n';
        for (auto &&i : isVisited)
        {
            i = false;
        }
        cout << "All paths are:\n";
        getAllPaths(graph, vertex_1, vertex_2, isVisited, to_string(vertex_1));
    }
    else
    {
        cout << "There is no path between the vertices " << vertex_1 << " & " << vertex_2 << '\n';
    }
    return 0;
}