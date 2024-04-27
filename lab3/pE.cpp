#include <bits/stdc++.h>
using namespace std;

int n = 8, x, y, t;
vector<bool> col, d1, d2;
vector<int> dama;
string damainv;
vector<string> sols;

void print() {
    cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
    for (int i = 0; i < sols.size(); i++) {
        i < 9 ? cout << " " << i + 1 : cout << i + 1;
        cout << "      ";
        for (int j = 0; j < n; j++) {
            cout << sols[i][j] + 1;
            j != 7 ? cout << " " : cout << "\n";
        }
    }
    if (t) cout << "\n";
}
void generar(int i) {
    if (i == n) {
        if (dama[x] != y) return;
        for (int i = 0; i < n; i++)
            damainv[dama[i]] = (char)i;
        sols.push_back(damainv);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (col[j] || d2[i + j] || d1[(n - 1 - i) + j]) continue;
        col[j] = d2[i + j] = d1[(n - 1 - i) + j] = true;
        dama[j] = i;
        generar(i + 1);
        col[j] = d2[i + j] = d1[(n - 1 - i) + j] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    string c;
    cin >> t;

    while (t--) {
        getline(cin, c);

        cin >> x >> y;
        x--;
        y--;
        col.resize(n, false);
        d1.resize(2 * n - 1, false);  /// d1(x,y) = (n-1 - x) + y;
        d2.resize(2 * n - 1, false);  /// d2(x,y) = x + y;
        dama.resize(n, -1);
        damainv.resize(n, -1);
        generar(0);
        print();
        col.clear();
        d1.clear();
        d2.clear();
        dama.clear();
        damainv.clear();
        sols.clear();
    }

    return 0;
}