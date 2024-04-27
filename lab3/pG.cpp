#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b) {
    vector<int> digits(10, 0);
    if (a < 10000 || b < 10000)
        digits[0]++;
    while (a) {
        digits[a % 10]++;
        a /= 10;
    }
    while (b) {
        digits[b % 10]++;
        b /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (digits[i] != 1) {
            return false;
        }
    }
    return true;
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

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        bool solved = false;
        for (int fgihj = 1234; fgihj <= 98765; fgihj++) {
            int abcde = fgihj * n;
            if (abcde > 98765) break;
            if (check(abcde, fgihj)) {
                solved = true;
                abcde < 10000 ? cout << "0" << abcde : cout << abcde;
                cout << " / ";
                fgihj < 10000 ? cout << "0" << fgihj : cout << fgihj;
                cout << " = " << n << '\n';
            }
        }
        if (!solved)
            cout << "There are no solutions for " << n << ".\n";
        cout << "\n";
    }
    return 0;
}