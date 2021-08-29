#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> create_graph(int, int);
void DFS(vector<vector<pair<int, int>>>);
void DFS(vector<vector<pair<int, int>>>, bool[], int);
bool isCyclic(vector<vector<pair<int, int>>>);
bool isCyclic(vector<vector<pair<int, int>>>, int[], int);
void topologicalSort(vector<vector<pair<int, int>>>);
void topologicalSort(vector<vector<pair<int, int>>>, bool[], int);

int main(void)
{
    int vertices, edges;
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> vertices >> edges;
    vector<vector<pair<int, int>>> graph = create_graph(vertices, edges);
    cout << "DFS: ";
    DFS(graph);
    cout << boolalpha << "Is Cycle present?: " << isCyclic(graph) << noboolalpha << '\n';
    cout << "Topological Sort: ";
    topologicalSort(graph);
    return 0;
}

vector<vector<pair<int, int>>> create_graph(int vertex, int edge)
{
    vector<vector<pair<int, int>>> graph(vertex);
    int vertex_1, vertex_2, weight;
    while (edge--)
    {
        cout << "Enter the edges with the weight (vi vf w): ";
        cin >> vertex_1 >> vertex_2 >> weight;
        graph[vertex_1].push_back(make_pair(vertex_2, weight));
    }
    return graph;
}

void DFS(vector<vector<pair<int, int>>> graph)
{
    int len = graph.size();
    bool visited[len];
    for (int vertex = 0; vertex < len; vertex++)
    {
        DFS(graph, visited, vertex);
    }
    cout << '\n';
}

void DFS(vector<vector<pair<int, int>>> graph, bool visited[], int currentVertex)
{
    if (!visited[currentVertex])
    {
        cout << currentVertex << ' ';
        visited[currentVertex] = true;
        for (int neighbour = 0; neighbour < (int)graph[currentVertex].size(); neighbour++)
        {
            DFS(graph, visited, graph[currentVertex][neighbour].first);
        }
    }
}

bool isCyclic(vector<vector<pair<int, int>>> graph)
{
    int len = graph.size();
    int flag[len];
    for (auto &&i : flag)
    {
        i = -1;
    }

    for (int vertex = 0; vertex < len; vertex++)
    {
        if (isCyclic(graph, flag, vertex))
        {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<vector<pair<int, int>>> graph, int flag[], int currentVertex)
{
    if (!flag[currentVertex])
    {
        return true;
    }

    if (flag[currentVertex] == -1)
    {
        flag[currentVertex] = 0;
        for (int neighbour = 0; neighbour < (int)graph[currentVertex].size(); neighbour++)
        {
            if (isCyclic(graph, flag, graph[currentVertex][neighbour].first))
            {
                return true;
            }
        }
        flag[currentVertex] = 1;
    }
    return false;
}

void topologicalSort(vector<vector<pair<int, int>>> graph)
{
    if (isCyclic(graph))
    {
        cout << "No Topological Sort Possible! :: Cycle Detected\n";
        return;
    }

    int len = graph.size();
    bool visited[len] = {false};
    for (int vertex = 0; vertex < len; vertex++)
    {
        topologicalSort(graph, visited, vertex);
    }
    cout << '\n';
}

void topologicalSort(vector<vector<pair<int, int>>> graph, bool visited[], int currentVertex)
{
    if (!visited[currentVertex])
    {
        visited[currentVertex] = true;
        for (int neighbour = 0; neighbour < (int)graph[currentVertex].size(); neighbour++)
        {
            topologicalSort(graph, visited, graph[currentVertex][neighbour].first);
        }
        cout << currentVertex << ' ';
    }
}