#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string temp;
    getline(cin, temp);

    vector<string> items(N);
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> color;
    unordered_map<string, bool> color_set;

    for (int i = 0; i < N; ++i) {
        getline(cin, items[i]);
        adj[items[i]] = vector<string>();
        color[items[i]] = false;
        color_set[items[i]] = false;
    }

    int M;
    cin >> M;
    getline(cin, temp);

    for (int i = 0; i < M; ++i) {
        string a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<string> walt, jessie;
    stack<string> stack;
    unordered_set<string> seen;

    for (const auto& name : items) {
        if (seen.find(name) != seen.end()) {
            continue;
        }
        color[name] = true;
        stack.push(name);
        while (!stack.empty()) {
            string n = stack.top();
            stack.pop();
            if (seen.find(n) != seen.end())
                continue;

            seen.insert(n);
            if (color[n])
                walt.push_back(n);
            else
                jessie.push_back(n);

            for (const auto& nbr : adj[n]) {
                if (!color_set[nbr]) {
                    color[nbr] = !color[n];
                    color_set[nbr] = true;
                    stack.push(nbr);
                } else if (color[nbr] == color[n]) {
                    cout << "impossible" << endl;
                    return 0;
                }
            }
        }
    }

    for (const auto& name : walt)
        cout << name << " ";

    cout << endl;
    for (const auto& name : jessie)
        cout << name << " ";

    cout << endl;
    return 0;
}
