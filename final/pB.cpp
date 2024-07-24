#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool check(vector<vector<ll>> &graph,
           vector<ll> &valid,
           vector<bool> &seen,
           ll current_node) {
    for (ll next : graph[current_node]) {
        if (!seen[next]) {
            seen[next] = true;
            if (valid[next] == -1 || check(graph, valid, seen, valid[next])) {
                valid[next] = current_node;
                return true;
            }
        }
    }
    return false;
}

ll find_min(ll tot, vector<vector<ll>> &graph) {
    vector<ll> valid(tot, -1);
    vector<bool> seen(tot, false);

    for (ll curr = 0; curr < tot; curr++) {
        fill(seen.begin(), seen.end(), false);
        check(graph, valid, seen, curr);
    }

    ll min_cost = 0;
    for (ll m : valid) {
        if (m != -1) {
            min_cost += 1;
        }
    }
    return min_cost / 2;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll tot = n + m;
    vector<vector<ll>> graph(tot);

    ll ki, cj;
    for (ll i = 0; i < n; i++) {
        cin >> ki;
        for (ll j = 0; j < ki; j++) {
            cin >> cj;
            graph[i].push_back(n + cj - 1);
            graph[n + cj - 1].push_back(i);
        }
    }

    cout << find_min(tot, graph);
    return 0;
}
