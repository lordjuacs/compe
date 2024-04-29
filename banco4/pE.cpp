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
    long int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string out(n, 'a');
        for (long int i = n - 2; i >= 0; i--) {
            if (k <= (n - i - 1)) {
                out[i] = 'b';
                out[n - k] = 'b';
                cout << out << '\n';
                break;
            }
            k -= (n - i - 1);
        }
    }
    return 0;
}