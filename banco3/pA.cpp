#include <bits/stdc++.h>
using namespace std;
int MAXN = (1e3);
int n = 8;
int cont = 0;
vector<bool> col, d1, d2;
vector<int> dama;
vector<pair<int, int>> invalid;
void revisar() {
    if (invalid.size() == 0) {
        cont++;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dama[i] == j) {
                for (auto p : invalid) {
                    if (p.first == i && p.second == j) {
                        return;
                    }
                }
            }
        }
    }
    cont++;
}

void generar(int i) {
    if (i == n) {
        revisar();
        return;
    }
    for (int j = 0; j < n; j++) {
        if (col[j] || d2[i + j] || d1[(n - 1 - i) + j]) continue;
        col[j] = d2[i + j] = d1[(n - 1 - i) + j] = true;
        dama[i] = j;
        generar(i + 1);
        col[j] = d2[i + j] = d1[(n - 1 - i) + j] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cin >> n;
    col.resize(n, false);
    d1.resize(2 * n - 1, false);  /// d1(x,y) = (n-1 - x) + y;
    d2.resize(2 * n - 1, false);  /// d2(x,y) = x + y;
    dama.resize(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char in;
            cin >> in;
            if (in == '*') {
                invalid.push_back({i, j});
            }
        }
    }
    generar(0);
    cout << cont << "\n";
    return 0;
}
//