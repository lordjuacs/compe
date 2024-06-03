#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& seen, vector<int>& cats, int s, int tot, int m, int& leaves) {
    if (seen[s])
        return;
    seen[s] = true;
    if (cats[s])
        tot += 1;
    else
        tot = 0;
    if (tot > m)
        return;
    if (s != 1 && adj[s].size() == 1)
        leaves += 1;
    for (int i : adj[s])
        dfs(adj, seen, cats, i, tot, m, leaves);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> seen(n + 1, false);
    vector<int> cats(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> cats[i];

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int leaves = 0;
    dfs(adj, seen, cats, 1, 0, m, leaves);

    cout << leaves << "\n";

    return 0;
}
