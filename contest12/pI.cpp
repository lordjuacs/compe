#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct rect {
    ll x1, y1, x2, y2;
    void init() {
        cin >> x1 >> y1 >> x2 >> y2;
    }
};

ll intersect(rect p, rect q) {
    ll x = max(0LL, min(p.x2, q.x2) - max(p.x1, q.x1));
    ll y = max(0LL, min(p.y2, q.y2) - max(p.y1, q.y1));
    return x * y;
}
ll intersect(rect p, rect q, rect t) {
    ll x = max(0LL, min({p.x2, q.x2, t.x2}) - max({p.x1, q.x1, t.x1}));
    ll y = max(0LL, min({p.y2, q.y2, t.y2}) - max({p.y1, q.y1, t.y1}));
    return x * y;
}

void solve() {
    rect w, b1, b2;
    w.init();
    b1.init();
    b2.init();
    ll ans = intersect(w, b1) + intersect(w, b2) - intersect(w, b1, b2);
    ll area = (w.x2 - w.x1) * (w.y2 - w.y1);
    if (ans < area) {
        cout << "YES";
    } else {
        cout << "NO\n";
    }
}

int main() {
    solve();
    return 0;
}