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
        long int n;
        cin >> n;
        vector<long int> notas(3 * n);
        for (long int i = 0; i < 3 * n; i++)
            cin >> notas[i];

        sort(notas.rbegin(), notas.rend());
        long int suma = 0;
        for (long int i = n; i < 2 * n; i++)
            suma += notas[i];
        sort(notas.begin(), notas.end());
        long int suma2 = 0;
        for (long int i = n; i < 2 * n; i++)
            suma2 += notas[i];
        cout << max(suma, suma2) << "\n";
    }

    return 0;
}
