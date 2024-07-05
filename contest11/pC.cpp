#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string& s) {
    vector<int> fi(s.size(), 0);
    int j = 0;
    for (int i = 1; i < s.size(); ++i) {
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

vector<int> count(string& s, string& p) {
    char sp = '-';
    while (p.find(sp) != string::npos || s.find(sp) != string::npos) {
        ++sp;
    }

    string combined = p + sp + s;
    vector<int> pre = prefix(combined);

    vector<int> c;
    int pattern_length = p.size();
    for (int i = 0; i < pre.size(); ++i) {
        if (pre[i] == pattern_length) {
            c.push_back(i - 2 * pattern_length);
        }
    }
    return c;
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
    string f, s;

    while (getline(cin, f)) {
        if (!getline(cin, s))
            break;

        vector<int> c = count(s, f);

        for (auto i : c)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
