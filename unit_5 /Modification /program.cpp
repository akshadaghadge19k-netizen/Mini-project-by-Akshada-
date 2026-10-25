#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const long long INF = numeric_limits<long long>::max() / 4;

void primMST(const vector<vector<long long > >& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    long long totalCost = 0;
    int edgesSelected = 0;

    visited[0] = true;

    cout << "\nSelected Pipelines:\n";
    cout << "Edge\tCost\tRunning Total\n";

    while (edgesSelected < n - 1) {
        long long minCost = INF;
        int u = -1, v = -1;

        // Find the minimum edge from a visited
        // tank to an unvisited tank.
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] &&
                        graph[i][j] < minCost) {
                        minCost = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // No edge connects the remaining tanks.
        if (u == -1)
            break;

        visited[v] = true;
        totalCost += minCost;
        edgesSelected++;

        cout << u + 1 << " - " << v + 1
             << "\t" << minCost
             << "\t" << totalCost << endl;
    }

    if (edgesSelected == n - 1) {
        cout << "Minimum total cost = "
             << totalCost << endl;
        cout << "A spanning tree can be formed.\n";
    } else {
        cout << "Graph is disconnected.\n";
        cout << "A spanning tree cannot be formed.\n";
    }
}

int main() {
    int n, m;

    cout << "Enter number of water tanks: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of tanks.\n";
        return 0;
    }

    vector<vector<long long > > graph(
        n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++)
        graph[i][i] = 0;

    cout << "Enter number of pipelines: ";
    if (!(cin >> m) || m < 0) {
        cout << "Invalid number of pipelines.\n";
        return 0;
    }

    cout << "Enter tank1 tank2 cost:\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;

        if (!(cin >> u >> v >> w) ||
            u < 1 || u > n ||
            v < 1 || v > n || u == v ||
            w >= INF || w <= -INF) {
            cout << "Invalid pipeline input.\n";
            return 0;
        }

        // Keep the minimum cost if a pipeline
        // between the same tanks is entered twice.
        if (w < graph[u - 1][v - 1]) {
            graph[u - 1][v - 1] = w;
            graph[v - 1][u - 1] = w;
        }
    }

    cout << "\nOriginal Minimum-Cost Network\n";
    primMST(graph);

    int u, v;
    long long newCost;

    cout << "\nEnter pipeline endpoints to update: ";

    if (!(cin >> u >> v) ||
        u < 1 || u > n ||
        v < 1 || v > n || u == v ||
        graph[u - 1][v - 1] == INF) {
        cout << "Pipeline does not exist. "
             << "No update performed.\n";
        return 0;
    }

    cout << "Enter new pipeline cost: ";

    if (!(cin >> newCost) ||
        newCost >= INF || newCost <= -INF) {
        cout << "Invalid pipeline cost.\n";
        return 0;
    }

    // Update the undirected edge in both directions.
    graph[u - 1][v - 1] = newCost;
    graph[v - 1][u - 1] = newCost;

    cout << "\nUpdated Minimum-Cost Network\n";
    primMST(graph);

    return 0;
}
