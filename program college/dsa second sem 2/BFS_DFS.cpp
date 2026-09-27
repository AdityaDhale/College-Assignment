#include <iostream>
#include <string>
using namespace std;

#define MAX 20

int graph[MAX][MAX];
string landmark[MAX];
int n;

// DFS
void DFS(int vertex, int visited[]) {

    cout << landmark[vertex] << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {

        if (graph[vertex][i] == 1 &&
            visited[i] == 0) {

            DFS(i, visited);
        }
    }
}

// BFS
void BFS(int start) {

    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0;
    int rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while (front < rear) {

        int vertex = queue[front++];

        cout << landmark[vertex] << " ";

        for (int i = 0; i < n; i++) {

            if (graph[vertex][i] == 1 &&
                visited[i] == 0) {

                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    cout << endl;
}

// Display adjacency matrix
void displayMatrix() {

    cout << "\nAdjacency Matrix:\n\n";

    cout << "    ";

    for (int i = 0; i < n; i++)
        cout << i << " ";

    cout << endl;

    for (int i = 0; i < n; i++) {

        cout << i << " : ";

        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";

        cout << endl;
    }
}

int main() {

    int choice;

    // Initialize graph
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter number of landmarks: ";
    cin >> n;

    // Input landmark names
    for (int i = 0; i < n; i++) {

        cout << "Enter landmark " << i << ": ";
        cin >> landmark[i];
    }

    // Input edges
    int edges;

    cout << "\nEnter number of paths/edges: ";
    cin >> edges;

    cout << "\nEnter paths using landmark numbers:\n";

    for (int i = 0; i < edges; i++) {

        int u, v;

        cout << "Enter path " << i + 1
             << " (source destination): ";

        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;   // Undirected graph
    }

    do {

        cout << "\n========== COLLEGE GRAPH MENU ==========\n";
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. Perform DFS\n";
        cout << "3. Perform BFS\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            displayMatrix();
            break;

        case 2: {

            int start;

            cout << "Enter starting landmark number: ";
            cin >> start;

            int visited[MAX] = {0};

            cout << "DFS Traversal: ";

            DFS(start, visited);

            cout << endl;

            break;
        }

        case 3: {

            int start;

            cout << "Enter starting landmark number: ";
            cin >> start;

            BFS(start);

            break;
        }

        case 4:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}