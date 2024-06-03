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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans;
        if (n % 2 == 0)
            ans = n / 2 - 1;
        else
            ans = n / 2;
        cout << ans << "\n";
    }
    return 0;
}