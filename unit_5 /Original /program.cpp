#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, e;

    cout << "Enter number of water tanks: ";
    cin >> n;

    cout << "Enter number of pipelines: ";
    cin >> e;

    if (n <= 0 || e < 0) {
        cout << "Invalid number of tanks or pipelines.";
        return 0;
    }

    vector<vector<int>> cost(
        n, vector<int>(n, INT_MAX)
    );

    for (int i = 0; i < n; i++)
        cost[i][i] = 0;

    cout << "Enter pipeline connections "
         << "(tank1 tank2 cost):\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 1 || u > n ||
            v < 1 || v > n || w < 0) {
            cout << "Invalid pipeline input.\n";
            return 0;
        }

        u--;
        v--;

        if (u != v) {
            cost[u][v] = min(cost[u][v], w);
            cost[v][u] = cost[u][v];
        }
    }

    vector<bool> selected(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);

    key[0] = 0;
    int totalCost = 0;
    int edgeCount = 0;

    cout << "\nSelected Pipeline Connections:\n";

    for (int count = 0; count < n; count++) {
        int u = -1;
        int minCost = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!selected[i] && key[i] < minCost) {
                minCost = key[i];
                u = i;
            }
        }

        if (u == -1) {
            break;
        }

        selected[u] = true;

        if (parent[u] != -1) {
            cout << "Tank " << parent[u] + 1
                 << " - Tank " << u + 1
                 << " : Cost = " << key[u] << '\n';

            totalCost += key[u];
            edgeCount++;
        }

        for (int v = 0; v < n; v++) {
            if (!selected[v] &&
                cost[u][v] != INT_MAX &&
                cost[u][v] < key[v]) {

                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    if (edgeCount != n - 1) {
        cout << "\nGraph is disconnected.\n";
        cout << "A spanning tree cannot connect "
             << "all water tanks.\n";
        cout << "Minimum cost of the connected "
             << "portion = " << totalCost << '\n';
    } else {
        cout << "\nMinimum total pipeline cost = "
             << totalCost << '\n';
        cout << "All water tanks are connected.\n";
    }

    return 0;
}
