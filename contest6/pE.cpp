#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    map<ll, ll> twos, rep;
    twos[0] = 1ll;
    for (ll i = 1; i < 30; i++)
        twos[i] = 2ll * twos[i - 1ll];
    ll m, op, val;
    cin >> m;
    for (ll i = 0; i < m; i++) {
        cin >> op >> val;
        if (op == 1) {
            rep[twos[val]]++;
        } else {
            for (ll j = 29; j >= 0; j--) {
                if (val >= twos[j] && val) {
                    if (rep[twos[j]])
                        val -= min(val / twos[j], rep[twos[j]]) * twos[j];
                }
            }
            if (!val)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    return 0;
}