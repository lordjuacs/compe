#include <bits/stdc++.h>
using namespace std;

void check(int n, int from, int mid, int to, vector<pair<int, int>>& moves) {
    if (n == 1) {
        moves.push_back({from, to});
        return;
    }
    check(n - 1, from, to, mid, moves);
    moves.push_back({from, to});
    check(n - 1, mid, from, to, moves);
}

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
    int n;
    cin >> n;
    int k = 0;
    vector<pair<int, int>> moves;
    check(n, 1, 2, 3, moves);
    cout << moves.size() << "\n";
    for (auto& x : moves) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
//