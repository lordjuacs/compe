#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void update(ll index, ll delta, vector<ll>& tree, ll n) {
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
    ll n, k;
    cin >> n >> k;

    vector<bool> memory(n, false);
    vector<ll> tree = vector<ll>(n + 1);

    char query;
    ll l, r, x;
    for (ll i = 0; i < k; ++i) {
        cin >> query;
        if (query == 'F') {
            cin >> x;
            // update x-th bit in memory
            memory[x - 1] = !memory[x - 1];
            update(x, memory[x - 1] ? 1 : -1, tree, n);
        } else if (query == 'C') {
            // count number of 1s in memory from l to r
            cin >> l >> r;
            cout << count(l, r, tree) << endl;
        }
    }
    return 0;
}
