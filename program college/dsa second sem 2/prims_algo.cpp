#include <iostream>
using namespace std;

#define INF 9999
#define MAX 20

int main()
{
    int n;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0, totalCost = 0;

    cout << "Enter number of warehouses: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    cout << "\nSelected Routes:\n";

    while (edges < n - 1)
    {
        int minCost = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < minCost)
                    {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1)
        {
            cout << "All warehouses cannot be connected.\n";
            return 0;
        }

        cout << "Warehouse " << u + 1
             << " -> Warehouse " << v + 1
             << " : Cost = " << minCost << endl;

        totalCost += minCost;
        visited[v] = 1;
        edges++;
    }

    cout << "\nMinimum Total Cost = " << totalCost << endl;

    return 0;
}