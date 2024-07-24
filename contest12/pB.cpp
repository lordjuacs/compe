#include <bits/stdc++.h>
using namespace std;

struct node {
    int r, c, d;
    bool operator<(const node& a) {
        return r < a.r;
    }
} ar[200050];

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

        ar[0] = {1, 1, 0};
        for (int i = 1; i <= n; i++)
            cin >> ar[i].r;
        for (int i = 1; i <= n; i++) {
            cin >> ar[i].c;
            ar[i].d = ar[i].r - ar[i].c;
        }

        sort(ar + 1, ar + 1 + n);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ar[i].d == ar[i - 1].d) {
                if (ar[i].d % 2 == 0)
                    ans += ar[i].c - ar[i - 1].c;
            } else {
                if (ar[i - 1].d % 2 == 0)
                    ans += (ar[i].d - ar[i - 1].d) / 2;
                else
                    ans += (ar[i].d - ar[i - 1].d + 1) / 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}