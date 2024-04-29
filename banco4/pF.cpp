#include <bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;

long long int powmod(long long int a, long long int b) {
    long long int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
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
    long long int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << powmod(a, b) << endl;
    }
    return 0;
}