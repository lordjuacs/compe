#include <bits/stdc++.h>
using namespace std;

vector<int> visited(10);

int check(map<char, int>& nps, const vector<string>& s) {
    if (nps[s[0][0]] == 0 || nps[s[1][0]] == 0 || nps[s[2][0]] == 0) return false;
    int n0 = 0, n1 = 0, n2 = 0, x = 1;
    for (int i = s[0].size() - 1; i >= 0; i--) {
        n0 += x * nps[s[0][i]];
        x *= 10;
    }
    x = 1;
    for (int i = s[1].size() - 1; i >= 0; i--) {
        n1 += x * nps[s[1][i]];
        x *= 10;
    }
    x = 1;
    for (int i = s[2].size() - 1; i >= 0; i--) {
        n2 += x * nps[s[2][i]];
        x *= 10;
    }
    return (n2 == (n0 + n1) && n0 && n1 && n2);
}

bool possible_nps(map<char, int>& nps, map<char, int>::iterator it, const vector<string>& s) {
    if (it->first == nps.rbegin()->first) {
        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                nps[it->first] = i;
                visited[i] = true;
                if (check(nps, s)) {
                    for (const auto& st : s) {
                        for (const auto& c : st)
                            cout << nps[c];
                        cout << "\n";
                    }
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            nps[it->first] = i;
            visited[i] = true;
            if (possible_nps(nps, next(it, 1), s))
                return true;
            visited[i] = false;
        }
    }
    return false;
}

bool find_np(const vector<string>& s) {
    map<char, int> rep;

    for (int i = 0; i < s[0].size(); i++) {
        if (rep.find(s[0][i]) == rep.end())
            rep[s[0][i]] = 0;
        rep[s[0][i]]++;
    }

    for (int i = 0; i < s[1].size(); i++) {
        if (rep.find(s[1][i]) == rep.end())
            rep[s[1][i]] = 0;
        rep[s[1][i]]++;
    }

    for (int i = 0; i < s[2].size(); i++) {
        if (rep.find(s[2][i]) == rep.end())
            rep[s[2][i]] = 0;
        rep[s[2][i]]++;
    }

    if (rep.size() > 10) return false;

    map<char, int> nps;
    for (auto& c : rep)
        nps[c.first] = -1;
    return possible_nps(nps, nps.begin(), s);
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
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];

    if (!find_np(s))
        cout << "UNSOLVABLE\n";
    return 0;
}
