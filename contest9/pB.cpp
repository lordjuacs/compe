#include <bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;

long long int powmod(long long int a, long long int b, long long int m) {
    if (a % m == 0) return 0;
    long long int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
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
    long long int t, n;
    cin >> t;
    while (t--) {
        long long int l, r, k;
        cin >> l >> r >> k;
        long long int base;
        base = 9 / k + 1;
        cout << (powmod(base, r, mod) - powmod(base, l, mod) + mod) % mod << '\n';
    }
    return 0;
}
