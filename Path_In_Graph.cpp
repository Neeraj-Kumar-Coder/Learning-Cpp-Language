#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> createGraph(int, int);
void printAdjacencyList(vector<vector<int>>, int);
bool findPath(vector<vector<int>>, int, int, bool[], string);
void findAllPaths(vector<vector<int>>, int, int, bool[], string);
void DFS(vector<vector<int>>, bool[]);
void DFS(vector<vector<int>>, bool[], int);
void DFS_noPrint(vector<vector<int>>, bool[], int);
bool isConnected(vector<vector<int>>, bool[]);
void getConnectedComponents(vector<vector<int>>, bool[]);
void hamiltonianPathOrCycle(vector<vector<int>>, set<int>, int, int, string);

int main(void)
{
    int vertex, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertex >> edges;
    vector<vector<int>> graph = createGraph(vertex, edges);
    bool isVisited[vertex] = {false};

    cout << boolalpha << "Is the graph connected?: " << isConnected(graph, isVisited) << noboolalpha << '\n';
    cout << "The DFS is: ";

    // Resetting visited array
    for (auto &&i : isVisited)
    {
        i = false;
    }

    DFS(graph, isVisited);
    cout << '\n';

    // Resetting visited array
    for (auto &&i : isVisited)
    {
        i = false;
    }

    int source, destination;
    cout << "Enter the source and the destination: ";
    cin >> source >> destination;
    if (!findPath(graph, source, destination, isVisited, to_string(source) + ""))
    {
        cout << "No Paths Exists!\n";
    }

    // Resetting visited array
    for (auto &&i : isVisited)
    {
        i = false;
    }

    cout << "All the possible paths between " << source << " and " << destination << " is:\n";
    findAllPaths(graph, source, destination, isVisited, to_string(source) + "");

    cout << "All the connected components are:\n";
    getConnectedComponents(graph, isVisited);

    // Resetting visited array
    for (auto &&i : isVisited)
    {
        i = false;
    }

    set<int> Isvisited;
    cout << "Enter the source for hamiltonian path or cycle: ";
    cin >> source;
    cout << "The Hamiltonian path is ended by \'.\' and cycle by \'@\':\n";
    hamiltonianPathOrCycle(graph, Isvisited, source, source, to_string(source) + "");
    return 0;
}

vector<vector<int>> createGraph(int vertices, int edges)
{
    int vertex_1, vertex_2;
    vector<vector<int>> graph(vertices);
    while (edges--)
    {
        cout << "Enter the edge: ";
        cin >> vertex_1 >> vertex_2;
        graph[vertex_1].push_back(vertex_2);
        graph[vertex_2].push_back(vertex_1);
    }
    return graph;
}

void printAdjacencyList(vector<vector<int>> graph, int vertices)
{
    for (int vertex = 0; vertex < vertices; vertex++)
    {
        cout << vertex << ": ";
        for (int adjacentVertex : graph[vertex])
        {
            cout << adjacentVertex << ' ';
        }
        cout << '\n';
    }
}

bool findPath(vector<vector<int>> graph, int source, int destination, bool visited[], string pathSoFar)
{
    if (source == destination)
    {
        cout << pathSoFar << '\n';
        return true;
    }

    visited[source] = true;
    for (int neighbour = 0; neighbour < (int)graph[source].size(); neighbour++)
    {
        if (!visited[graph[source][neighbour]] && findPath(graph, graph[source][neighbour], destination, visited, pathSoFar + "-" + to_string(graph[source][neighbour])))
        {
            return true;
        }
    }
    return false;
}

void findAllPaths(vector<vector<int>> graph, int source, int destination, bool visited[], string pathSoFar)
{
    if (source == destination)
    {
        cout << pathSoFar << '\n';
        return;
    }

    visited[source] = true;
    for (int neighbour = 0; neighbour < (int)graph[source].size(); neighbour++)
    {
        if (!visited[graph[source][neighbour]])
        {
            findAllPaths(graph, graph[source][neighbour], destination, visited, pathSoFar + "-" + to_string(graph[source][neighbour]));
        }
    }
    visited[source] = false;
}

void DFS(vector<vector<int>> graph, bool visited[])
{
    for (int vertex = 0; vertex < (int)graph.size(); vertex++)
    {
        if (!visited[vertex])
        {
            DFS(graph, visited, vertex);
        }
    }
}

void DFS(vector<vector<int>> graph, bool visited[], int currentVertex)
{
    if (!visited[currentVertex])
    {
        cout << currentVertex << ' ';
        visited[currentVertex] = true;
        for (int neighbour = 0; neighbour < (int)graph[currentVertex].size(); neighbour++)
        {
            DFS(graph, visited, graph[currentVertex][neighbour]);
        }
    }
}

void DFS_noPrint(vector<vector<int>> graph, bool visited[], int currentVertex)
{
    if (!visited[currentVertex])
    {
        visited[currentVertex] = true;
        for (int neighbour = 0; neighbour < (int)graph[currentVertex].size(); neighbour++)
        {
            DFS_noPrint(graph, visited, graph[currentVertex][neighbour]);
        }
    }
}

bool isConnected(vector<vector<int>> graph, bool visited[])
{
    DFS_noPrint(graph, visited, 0);
    for (int vertex = 0; vertex < (int)graph.size(); vertex++)
    {
        if (!visited[vertex])
        {
            return false;
        }
    }
    return true;
}

void getConnectedComponents(vector<vector<int>> graph, bool visited[])
{
    for (int vertex = 0; vertex < (int)graph.size(); vertex++)
    {
        if (!visited[vertex])
        {
            DFS(graph, visited, vertex);
            cout << '\n';
        }
    }
}

void hamiltonianPathOrCycle(vector<vector<int>> graph, set<int> visited, int originalSource, int currentVertex, string pathSoFar)
{
    if (visited.size() == graph.size() - 1)
    {
        cout << pathSoFar;
        bool isHamiltonianCycle = false;
        for (int vertex : graph[currentVertex])
        {
            if (vertex == originalSource)
            {
                isHamiltonianCycle = true;
                break;
            }
        }
        if (isHamiltonianCycle)
        {
            cout << " @\n";
        }
        else
        {
            cout << " .\n";
        }
        return;
    }

    visited.insert(currentVertex);
    for (int neighbour = 0; neighbour < (int)graph[currentVertex].size(); neighbour++)
    {
        if (visited.find(graph[currentVertex][neighbour]) == visited.end())
        {
            hamiltonianPathOrCycle(graph, visited, originalSource, graph[currentVertex][neighbour], pathSoFar + "-" + to_string(graph[currentVertex][neighbour]));
        }
    }
    visited.erase(currentVertex);
}