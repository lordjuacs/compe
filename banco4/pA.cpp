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
    long long int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        long long int diff = abs(a - b);
        cout << ((diff == 0) ? 0 : ((diff % 10 == 0) ? diff / 10 : (diff / 10) + 1)) << "\n";
    }
    return 0;
}