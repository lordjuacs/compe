#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cin >> n;
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    map<int, int> dic;
    int n, m;
    cin >> n >> m;
    int max = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (dic.count(i + j) > 0) {
                dic[i + j]++;
                if (dic[i + j] > max) {
                    max = dic[i + j];
                }
            } else {
                dic[i + j] = 1;
            }
        }
    }

    for (auto& x : dic) {
        if (x.second == max) {
            cout << x.first << "\n";
        }
    }
    return 0;
}
//