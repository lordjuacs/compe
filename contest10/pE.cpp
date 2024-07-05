#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void update(ll index, ll u, vector<ll>& memory, vector<ll>& tree, ll n) {
    ll delta = u - memory[index - 1];
    memory[index - 1] = u;
    while (index <= n) {
        tree[index] += delta;
        index += index & -index;
    }
}
ll left_count(ll index, vector<ll>& tree) {
    ll sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & -index;
    }
    return sum;
}

ll count(ll l, ll r, vector<ll>& tree) {
    return left_count(r, tree) - left_count(l - 1, tree);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;

    vector<ll> memory(n, 0);
    vector<ll> tree = vector<ll>(n + 1);

    ll query;
    ll l, r, k, u;
    for (ll i = 0; i < n; ++i) {
        cin >> u;
        // memory[i];
        update(i + 1, u, memory, tree, n);
    }
    for (ll i = 0; i < q; ++i) {
        cin >> query;
        if (query == 1) {
            cin >> k >> u;
            // update k-th bit in memory with u

            update(k, u, memory, tree, n);
        } else {
            // count number of 1s in memory from l to r
            cin >> l >> r;
            cout << count(l, r, tree) << endl;
        }
    }
    return 0;
}
