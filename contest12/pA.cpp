#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 998244353;
ll N = 100000 * 3 + 1;

vector<ll> colors;
vector<vector<ll>> adj;
vector<ll> track(2, 0);
vector<long long> pre(N, 1);

bool dfs(ll node, ll curr, bool& valid) {
    if (valid) {
        return valid;
    }

    colors[node] = curr;
    track[curr] += 1;

    for (ll v : adj[node]) {
        if (colors[v] == -1) {
            valid = dfs(v, 1 - curr, valid);
        } else if (colors[v] == curr) {
            valid = true;
            return valid;
        }
    }
    return valid;
}

long long solve(ll n, const vector<pair<ll, ll>>& edges, bool& valid) {
    for (ll i = 1; i <= n; ++i) {
        adj[i].clear();
        colors[i] = -1;
    }

    for (const auto& edge : edges) {
        ll u = edge.first, v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long tot = 1;

    for (ll i = 1; i <= n; ++i) {
        if (colors[i] == -1) {
            valid = false;
            track[0] = track[1] = 0;

            valid = dfs(i, 0, valid);

            if (valid) {
                return 0;
            }

            long long other = (pre[track[0]] + pre[track[1]]) % mod;
            tot = (tot * other) % mod;
        }
    }

    return tot;
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
    for (ll i = 1; i < N; ++i) {
        pre[i] = (2 * pre[i - 1]) % mod;
    }

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> edges(m);
        for (ll i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }

        colors.assign(n + 1, -1);
        adj.assign(n + 1, vector<ll>());
        track = {0, 0};
        bool valid = false;
        cout << solve(n, edges, valid) << endl;
    }

    return 0;
}
