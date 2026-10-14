#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter number of connections: ";
    cin >> m;

    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        cost[i][i] = 0;

    cout << "Enter connections (router1 router2 cost):\n";

    for (int i = 0; i < m; i++)
    {
        char u, v;
        int c;

        cin >> u >> v >> c;

        int a = u - 'A';
        int b = v - 'A';

        cost[a][b] = c;
        cost[b][a] = c;
    }

    char source, destination;

    cout << "Enter source router (A, B, C...): ";
    cin >> source;

    cout << "Enter destination router (A, B, C...): ";
    cin >> destination;

    int s = source - 'A';
    int dest = destination - 'A';

    vector<int> d(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    d[s] = 0;

    // Dijkstra's algorithm
    for (int i = 0; i < n; i++)
    {
        int u = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] &&
                (u == -1 || d[j] < d[u]))
                u = j;
        }

        if (u == -1 || d[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                cost[u][v] != INT_MAX &&
                d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\n========================================\n";
    cout << "         SHORTEST PATH DETAILS\n";
    cout << "========================================\n";

    if (d[dest] == INT_MAX)
    {
        cout << "No path exists from "
             << source << " to " << destination << ".\n";
    }
    else
    {
        vector<int> path;

        for (int v = dest; v != -1; v = parent[v])
            path.push_back(v);

        cout << "Shortest path: ";

        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << char('A' + path[i]);

            if (i > 0)
                cout << " -> ";
        }

        cout << "\nMinimum cost: " << d[dest] << endl;
    }

    cout << "\n========================================\n";
    cout << "       SHORTEST DISTANCE TABLE\n";
    cout << "========================================\n";

    cout << left << setw(15) << "Source Node"
         << setw(15) << "Destination"
         << "Shortest Distance\n";

    cout << "----------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(15) << source
             << setw(15) << char('A' + i);

        if (d[i] == INT_MAX)
            cout << "Infinity";
        else
            cout << d[i];

        cout << endl;
    }

    return 0;
}