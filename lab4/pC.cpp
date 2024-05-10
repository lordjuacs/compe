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
        cin >> n;
        long long int m3 = n % 3;
        if (n < 3)
            cout << n << '\n';
        else if (m3 == 0)
            cout << powmod(3, n / 3, mod) % mod << '\n';
        else if (m3 == 1)
            cout << (powmod(3, (n - 4) / 3, mod) * 4) % mod << '\n';
        else
            cout << (powmod(3, (n - 2) / 3, mod) * 2) % mod << '\n';
    }
    return 0;
}