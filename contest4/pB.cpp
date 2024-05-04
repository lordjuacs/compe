#include <bits/stdc++.h>
using namespace std;

long long int mod = 10000007;

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
    long long int n, k;
    while (cin >> n >> k) {
        if (!n && !k) break;

        long long int a = powmod(n, k, mod) % mod;
        long long int b = (2 * powmod(n - 1, k, mod) % mod) % mod;
        long long int c = powmod(n, n, mod) % mod;
        long long int d = (2 * powmod(n - 1, n - 1, mod) % mod) % mod;
        long long int ans = (((a + b) % mod + c) % mod + d) % mod;
        cout << ans << '\n';
    }
    return 0;
}