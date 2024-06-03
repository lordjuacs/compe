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
    string s, target = "hello";
    cin >> s;
    int cont = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target[cont]) cont++;
        if (cont == 5) {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "YES" << "\n";
    else

        cout << "NO" << "\n";

    return 0;
}