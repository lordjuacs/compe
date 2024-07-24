#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> tree;

void update(ll pos, ll dif) {
    while (pos < tree.size()) {
        tree[pos] += dif;
        pos |= pos + 1;
    }
}

ll lower_bound(ll sum) {
    if (sum <= 0) return -1;
    ll pos = 0;
    ll pw = 1 << 25;
    while (pw > 0) {
        if (pos + pw <= tree.size() && tree[pos + pw - 1] < sum) {
            pos += pw;
            sum -= tree[pos - 1];
        }
        pw >>= 1;
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distllos parametros aqui.

    */
    ll n;
    cin >> n;
    n /= 2;
    tree.resize(2 * n, 0);

    for (ll i = 0; i < 2 * n; ++i)
        update(i, 1);

    vector<ll> first(n);
    vector<ll> second(n);

    for (ll i = 0; i < n; ++i) {
        cin >> first[i];
    }

    for (ll i = 0; i < n; ++i) {
        cin >> second[i];
    }

    vector<ll> first_choice(n);
    vector<ll> second_choice(n);

    for (ll i = 0; i < n; ++i) {
        first_choice[i] = lower_bound(first[i]);
        update(first_choice[i], -1);
        second_choice[i] = lower_bound(second[i]);
        update(second_choice[i], -1);
    }

    for (ll i = 0; i < n; ++i)
        cout << first_choice[i] + 1 << " ";
    cout << endl;

    for (ll i = 0; i < n; ++i)
        cout << second_choice[i] + 1 << " ";

    cout << endl;

    return 0;
}
