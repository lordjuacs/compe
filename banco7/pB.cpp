#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const long int MAXN = 1000005;
long int link[MAXN], len[MAXN];

long int find(long int a) {
    while (a != link[a]) a = link[a];
    return a;
}

void join(long int a, long int b) {
    if (find(a) == find(b)) return;
    long int x = find(a), y = find(b);
    if (len[x] > len[y]) swap(x, y);
    len[y] += len[x];
    link[x] = y;
}

void kruskal() {
    long int n, m;
    cin >> n >> m;
    vector<tuple<long int, long int, long int>> edges;
    for (long int i = 0; i < m; i++) {
        long int w, a, b;
        cin >> a >> b >> w;
        edges.emplace_back(w, a, b);
    }

    sort(edges.begin(), edges.end());

    for (long int i = 1; i <= n; i++) {
        link[i] = i;
        len[i] = 1;
    }

    long int total_cost = 0;
    for (auto &e : edges) {
        auto w = get<0>(e);
        auto a = get<1>(e);
        auto b = get<2>(e);
        if (find(a) != find(b)) {
            total_cost += w;
            join(a, b);
        }
    }

    long int components = 0;
    for (long int i = 1; i <= n; i++) {
        if (link[i] == i) components++;
    }

    if (components == 1) {
        cout << total_cost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    kruskal();
    return 0;
}
