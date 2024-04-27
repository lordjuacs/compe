#include <bits/stdc++.h>
using namespace std;
int MAXN = (1e3);
int n;
vector<bool> col, d1, d2;
vector<int> dama;

void printear() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = '.';
            if (dama[i] == j) c = 'q';
            cout << c << "\n "[j + 1 < n];
        }
    }
    cout << "-----\n";
}

/// generar(i) se encarga de contar y generar todas las soluciones de llenar n damas
/// habiendo ubicado las primeras i damas, en las primeras i filas
void generar(int i) {
    if (i == n) {
        printear();
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
    cin >> n;
    col.resize(n, false);
    d1.resize(2 * n - 1, false);  /// d1(x,y) = (n-1 - x) + y;
    d2.resize(2 * n - 1, false);  /// d2(x,y) = x + y;
    dama.resize(n, -1);
    generar(0);
    return 0;
}
