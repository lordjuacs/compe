
#include <bits/stdc++.h>

using namespace std;

// Depth-First Search function
void dfs(int v, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

// Function to determine reachable nodes
vector<bool> reachable(int n, int m, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
        int a = edge.first;
        int b = edge.second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    dfs(1, graph, visited);

    return visited;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<bool> connected = reachable(n, m, edges);
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (!connected[i]) {
            cout << i << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "Connected" << endl;
    }

    return 0;
}
