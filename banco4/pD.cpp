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
    long int n, t;
    cin >> n >> t;
    vector<long double> d(n);
    vector<long double> s(n);
    for (long int i = 0; i < n; i++)
        cin >> d[i] >> s[i];

    long double left = -*min_element(s.begin(), s.end()) + 1e-9;
    long double right = 1e9;
    int x = 100000;
    while (x--) {
        long double c = (left + right) / 2;
        long double tot = 0;
        for (long int i = 0; i < n; i++) {
            tot += (d[i] / (s[i] + c));
        }
        if (tot >= t) {
            left = c;
        } else {
            right = c;
        }
    }
    cout << fixed << setprecision(9) << left << endl;

    return 0;
}