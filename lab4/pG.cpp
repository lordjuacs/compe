#include <bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;

long long int powmod(long long int a, long long int b, long long int m) {
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
    long long int n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        if (a % mod == 0) {
            if (c == 0 || b > 0) {
                cout << 0 << "\n";
                continue;
            }
            if (b == 0 && c > 0) {
                cout << 1 << "\n";
                continue;
            }
        }
        cout << powmod(a, powmod(b, c, mod - 1), mod) << "\n";
    }

    return 0;
}