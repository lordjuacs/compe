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
    string s;
    int n;
    int c = 0;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << "Case " << ++c << ":\n";
        int m;
        cin >> m;
        for (int x = 0; x < m; x++) {
            int query;
            cin >> query;
            int closest = v[0] + v[1];

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int current = v[i] + v[j];
                    if (abs(query - current) < abs(query - closest))
                        closest = current;
                }
            }
            cout << "Closest sum to " << query << " is " << closest << ".\n";
        }
    }
    return 0;
}