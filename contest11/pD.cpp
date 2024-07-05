#include <bits/stdc++.h>
using namespace std;

vector<long long int> prefix(string& s) {
    vector<long long int> fi(s.size(), 0);
    long long int j = 0;
    for (long long int i = 1; i < s.size(); ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = fi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        fi[i] = j;
    }
    return fi;
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

    long long int L;
    string s;
    cin >> L >> s;

    vector<long long int> pre = prefix(s);
    cout << L - pre[L - 1] << "\n";

    return 0;
}
