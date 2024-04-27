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
    map<string, int> m;
    int n;
    cin >> n;
    vector<pair<string, string>> ans;
    for (int i = 0; i < n; i++) {
        string ac, name;
        cin >> ac >> name;
        if (m.find(name) == m.end()) {
            m[name] = 0;
        }
        if (ac == "entry")
            m[name]++;
        else if (ac == "exit")
            m[name]--;

        if (m[name] == 1) {
            ans.push_back({name, "entered"});
        } else if (m[name] > 1) {
            ans.push_back({name, "entered (ANOMALY)"});
            m[name] = 1;
        } else if (m[name] == 0) {
            ans.push_back({name, "exited"});
        } else if (m[name] < 0) {
            ans.push_back({name, "exited (ANOMALY)"});
            m[name] = 0;
        }
    }
    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
