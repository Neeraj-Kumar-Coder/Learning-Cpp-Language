#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Pair
{
public:
    int vertex;
    string pathSoFar;
    int weightSoFar;
    Pair(void) {}
    Pair(int vertex, string pathSoFar, int weightSoFar)
    {
        this->vertex = vertex;
        this->pathSoFar = pathSoFar;
        this->weightSoFar = weightSoFar;
    }
};

class Compare
{
public:
    bool operator()(Pair *a, Pair *b)
    {
        return a->weightSoFar > b->weightSoFar;
    }
};

vector<vector<pair<int, int>>> create_graph(int, int);
ostream &operator<<(ostream &, const Pair *);
void DijkstrasAlgorithm(vector<vector<pair<int, int>>>, int);

int main(void)
{
    int vertex, edge;
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> vertex >> edge;
    vector<vector<pair<int, int>>> graph = create_graph(vertex, edge);
    int source;
    cout << "Enter the source vertex to find all the shortest distances: ";
    cin >> source;
    DijkstrasAlgorithm(graph, source);
    return 0;
}

vector<vector<pair<int, int>>> create_graph(int vertex, int edge)
{
    vector<vector<pair<int, int>>> graph(vertex);
    int vertex1, vertex2, weight;
    while (edge--)
    {
        cout << "Enter the edge (vi, vf, w) : ";
        cin >> vertex1 >> vertex2 >> weight;
        graph[vertex1].push_back(make_pair(vertex2, weight));
        graph[vertex2].push_back(make_pair(vertex1, weight));
    }
    return graph;
}

ostream &operator<<(ostream &out, const Pair *obj)
{
    out << obj->vertex << " via " << obj->pathSoFar << "\b @ " << obj->weightSoFar << '\n';
    return out;
}

void DijkstrasAlgorithm(vector<vector<pair<int, int>>> graph, int source)
{
    priority_queue<Pair *, vector<Pair *>, Compare> vertexQueue;
    bool visited[graph.size()] = {false};
    Pair *vertex;

    vertexQueue.push(new Pair(source, to_string(source) + "-", 0));

    while (!vertexQueue.empty())
    {
        vertex = vertexQueue.top();
        vertexQueue.pop();
        if (!visited[vertex->vertex])
        {
            cout << vertex;
        }
        visited[vertex->vertex] = true;

        for (int neighbour = 0; neighbour < (int)graph[vertex->vertex].size(); neighbour++)
        {
            if (!visited[graph[vertex->vertex][neighbour].first])
            {
                vertexQueue.push(new Pair(graph[vertex->vertex][neighbour].first, vertex->pathSoFar + to_string(graph[vertex->vertex][neighbour].first) + "-", vertex->weightSoFar + graph[vertex->vertex][neighbour].second));
            }
        }
    }
}