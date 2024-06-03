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
        long int n, l;
        cin >> l >> n;
        long int pos[n];
        priority_queue<long int> fast;
        priority_queue<long int> slow;
        for (long int i = 0; i < n; i++)
            cin >> pos[i];
        for (long int i = 0; i < n; i++) {
            long int to_start = abs(pos[i] - 0);
            long int to_end = abs(l - pos[i]);
            if (to_start > to_end) {
                slow.push(to_start);
                fast.push(to_end);
            } else {
                slow.push(to_end);
                fast.push(to_start);
            }
        }
        cout << fast.top() << " " << slow.top() << "\n";
    }
    return 0;
}
