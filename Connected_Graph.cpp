#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> graph, bool isVisited[], int currentVertex)
{
    if (!isVisited[currentVertex])
    {
        isVisited[currentVertex] = true;
        for (auto &&neighbour : graph[currentVertex])
        {
            DFS(graph, isVisited, neighbour);
        }
    }
}

bool isConnected(vector<vector<int>> graph, bool isVisited[], int vertex, int currentVertex = 0)
{
    DFS(graph, isVisited, currentVertex);
    for (int i = 0; i < vertex; i++)
    {
        if (!isVisited[i])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int vertex, edges;
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex);
    int vertex1, vertex2;
    while (edges--)
    {
        cout << "Enter the edge: ";
        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }
    cout << "The adjacency list of the graph is:\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < (int)graph[i].size(); j++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    bool isVisited[vertex] = {false};
    cout << boolalpha << "The graph is connected?: " << isConnected(graph, isVisited, vertex) << '\n'
         << noboolalpha;
    return 0;
}