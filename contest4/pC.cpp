#include <bits/stdc++.h>
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
    long double n, k;
    cin >> n >> k;
    vector<long double> batmanacci(n + 1, 0);
    batmanacci[0] = 0;
    batmanacci[1] = 1;
    for (long double i = 2; i <= n; i++)
        batmanacci[i] = batmanacci[i - 1] + batmanacci[i - 2];
    while (n > 2) {
        if (k > batmanacci[n - 2]) {
            k -= batmanacci[n - 2];
            n -= 1;
        } else
            n -= 2;
    }
    cout << ((n == 1) ? "N" : "A") << "\n";
    return 0;
}