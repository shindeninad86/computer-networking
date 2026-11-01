#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        cost[i][i] = 0;

    cout << "Enter source(u), cost c(u,v), destination(v):\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> w >> v;
        cost[u][v] = w;
        cost[v][u] = w;  // For an undirected graph
    }

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++)
            if (!visited[j] &&
                (u == -1 || dist[j] < dist[u]))
                u = j;

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (cost[u][v] != INT_MAX &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    cout << "\nShortest Distance Table\n";
    cout << "Source\tDestination\tDistance\n";

    for (int i = 0; i < n; i++) {
        cout << s << "\t" << i << "\t\t";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}