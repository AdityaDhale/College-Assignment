#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int vertex;
    int weight;
    Node* next;
};

class Graph
{
    int V;
    Node** adj;

public:

    Graph(int n)
    {
        V = n;
        adj = new Node*[V];

        for (int i = 0; i < V; i++)
            adj[i] = NULL;
    }

    // Add edge
    void addEdge(int u, int v, int w)
    {
        Node* newNode = new Node;
        newNode->vertex = v;
        newNode->weight = w;
        newNode->next = adj[u];
        adj[u] = newNode;

        // Undirected graph
        newNode = new Node;
        newNode->vertex = u;
        newNode->weight = w;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Display adjacency list
    void display()
    {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            Node* temp = adj[i];

            while (temp != NULL)
            {
                cout << temp->vertex
                     << "(" << temp->weight << ") ";

                temp = temp->next;
            }

            cout << endl;
        }
    }

    // Find minimum distance vertex
    int findMin(int dist[], bool visited[])
    {
        int min = INT_MAX;
        int index = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                index = i;
            }
        }

        return index;
    }

    // Dijkstra's Algorithm
    void dijkstra(int source, int dist[])
    {
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[source] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            int u = findMin(dist, visited);

            if (u == -1)
                break;

            visited[u] = true;

            Node* temp = adj[u];

            while (temp != NULL)
            {
                int v = temp->vertex;
                int w = temp->weight;

                if (!visited[v] &&
                    dist[u] != INT_MAX &&
                    dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }

                temp = temp->next;
            }
        }

        delete[] visited;
    }

    // Find reachable power stations
    void findReachable(int source, int timeLimit)
    {
        int* dist = new int[V];

        dijkstra(source, dist);

        cout << "\nReachable Power Stations within "
             << timeLimit << " units:\n";

        bool found = false;

        for (int i = 0; i < V; i++)
        {
            if (dist[i] <= timeLimit)
            {
                cout << "Station " << i
                     << " : " << dist[i] << " units\n";

                found = true;
            }
        }

        if (!found)
            cout << "No power station is reachable.";

        delete[] dist;
    }

    ~Graph()
    {
        for (int i = 0; i < V; i++)
        {
            Node* temp = adj[i];

            while (temp != NULL)
            {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }

        delete[] adj;
    }
};

int main()
{
    int V, E;

    cout << "Enter number of power stations: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of connections: ";
    cin >> E;

    cout << "Enter source, destination and maintenance time:\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g.addEdge(u, v, w);
    }

    // Display graph
    g.display();

    int source, timeLimit;

    cout << "\nEnter starting power station: ";
    cin >> source;

    cout << "Enter maximum time limit: ";
    cin >> timeLimit;

    // Find reachable stations
    g.findReachable(source, timeLimit);

    return 0;
}