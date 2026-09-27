#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of keys: ";
    cin >> n;

    int key[n];
    float p[n];

    cout << "Enter sorted keys:\n";
    for (int i = 0; i < n; i++)
        cin >> key[i];

    cout << "Enter search probabilities:\n";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    float cost[n][n];

    // Cost of a single key
    for (int i = 0; i < n; i++)
        cost[i][i] = p[i];

    // Calculate minimum cost
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length; i++)
        {
            int j = i + length - 1;

            cost[i][j] = 9999;

            float sum = 0;
            for (int k = i; k <= j; k++)
                sum += p[k];

            for (int r = i; r <= j; r++)
            {
                float left = (r > i) ? cost[i][r - 1] : 0;
                float right = (r < j) ? cost[r + 1][j] : 0;

                float total = left + right + sum;

                if (total < cost[i][j])
                    cost[i][j] = total;
            }
        }
    }

    cout << fixed << setprecision(2);

    cout << "\nMinimum Expected Search Cost = "
         << cost[0][n - 1] << endl;

    return 0;
}