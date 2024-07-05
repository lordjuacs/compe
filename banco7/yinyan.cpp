#include <bits/stdc++.h>

using namespace std;

long long int check(vector<vector<long long int>>& dist, vector<bool>& seen, long long int curr, long long int n) {
    long long int tot = 0;
    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < n; ++j) {
            dist[i][j] = min(dist[i][j], dist[i][curr] + dist[curr][j]);
            if (seen[i] && seen[j]) {
                tot += dist[i][j];
            }
        }
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n;
    cin >> n;

    vector<vector<long long int>> dist(n, vector<long long int>(n));
    for (long long int i = 0; i < n; ++i)
        for (long long int j = 0; j < n; ++j)
            cin >> dist[i][j];

    vector<long long int> todel(n);
    for (long long int i = 0; i < n; ++i)
        cin >> todel[i];

    vector<long long int> ans(n, 0);
    vector<bool> seen(n, false);

    for (long long int k = n - 1; k >= 0; --k) {
        long long int curr = todel[k] - 1;
        seen[curr] = true;
        ans[k] = check(dist, seen, curr, n);
    }

    for (long long int i = 0; i < n; ++i)
        cout << ans[i] << " ";

    cout << "\n";

    return 0;
}
