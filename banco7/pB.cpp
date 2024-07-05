#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_weights(vector<bool> &visited, vector<vector<int>> &parent, int p,
                unordered_map<int, unordered_map<int, int>> &mine) {
    visited.clear();
    visited.resize(p, false);
    int ans = 0;
    queue<int> q;
    q.push(p - 1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        for (auto e : parent[curr]) {
            ans += mine[curr][e];
            q.push(e);
        }
    }
    return ans;
}

void djikstra(vector<bool> &visited, vector<vector<pair<int, int>>> &g, vector<int> &distance, vector<vector<int>> &parent) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        int curr = q.top().second;
        q.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        for (auto e : g[curr]) {
            int l = e.first;
            int next = e.second;
            if (distance[curr] + l < distance[next]) {
                distance[next] = distance[curr] + l;
                parent[next].clear();
                parent[next].push_back(curr);
                q.emplace(distance[next], next);
            } else if (distance[curr] + l == distance[next]) {
                parent[next].push_back(curr);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p, t;
    cin >> p >> t;
    int p1, p2, l;
    vector<vector<pair<int, int>>> g(p);
    unordered_map<int, unordered_map<int, int>> mine;
    vector<bool> visited(p);
    vector<int> distance(p, INT_MAX);
    vector<vector<int>> parent(p);
    distance[0] = 0;
    for (int i = 0; i < t; ++i) {
        cin >> p1 >> p2 >> l;
        if (p1 == p2) continue;
        g[p1].emplace_back(l, p2);
        g[p2].emplace_back(l, p1);
        if (mine.count(p1) == 0 || mine[p1].count(p2) == 0) {
            mine[p1][p2] = l;
            mine[p2][p1] = l;
        } else {
            mine[p1][p2] = min(mine[p1][p2], l);
            mine[p2][p1] = min(mine[p2][p1], l);
        }
    }
    djikstra(visited, g, distance, parent);
    cout << 2 * get_weights(visited, parent, p, mine);
    return 0;
}