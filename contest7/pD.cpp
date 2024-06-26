#include <bits/stdc++.h>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define e "\n"
#define endl "\n"
using namespace std;
#define Tp template <class T>
#define Tp2 template <class T1, class T2>
#define Tps template <class T, class... Ts>
#define Tps2 template <class T1, class T2, class... Ts>
#define ff first
#define ss second
#define rev(a) reverse(a.begin(), a.end())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define MOD 1000000007                 // 1e9 + 7
#define INF 2000000000                 // 2e9
#define DESPACITO 1000000000000000000  // 1e18
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace maxmin {
Tp T max(T&& a) { return a; }
Tp T min(T&& a) { return a; }
Tp T max(T&& a, T&& b) { return a > b ? a : b; }
Tp T min(T&& a, T&& b) { return a < b ? a : b; }
Tps T max(T&& a, Ts&&... ts) {
    T b = max(ts...);
    return a > b ? a : b;
}
Tps T min(T&& a, Ts&&... ts) {
    T b = min(ts...);
    return a < b ? a : b;
}
Tps T chmax(T&& a, Ts&&... ts) {
    a = max(a, ts...);
    return a;
}
Tps T chmin(T&& a, Ts&&... ts) {
    a = min(a, ts...);
    return a;
}
}  // namespace maxmin
namespace input {
Tp void re(T&& x) { cin >> x; }
Tp2 void re(pair<T1, T2>& p) {
    re(p.ff);
    re(p.ss);
}
Tp void re(vector<T>& a) {
    for (int i = 0; i < sz(a); i++) re(a[i]);
}
Tp2 void rea(T1&& a, T2 t) {
    for (int i = 0; i < t; i++) re(a[i]);
}
Tps2 void rea(T1&& a, T2 t, Ts&&... ts) {
    rea(a, t);
    rea(ts...);
}
Tp2 void rea1(T1&& a, T2 t) {
    for (int i = 1; i <= t; i++) re(a[i]);
}
Tps2 void rea1(T1&& a, T2 t, Ts&... ts) {
    rea1(a, t);
    rea1(ts...);
}
Tps void re(T&& t, Ts&... ts) {
    re(t);
    re(ts...);
}
}  // namespace input
namespace output {
void pr(int x) { cout << x; }
// void pr(num x) { cout << x; }
void pr(bool x) { cout << x; }
void pr(long long x) { cout << x; }
void pr(long long unsigned x) { cout << x; }
void pr(double x) { cout << x; }
void pr(char x) { cout << x; }
void pr(const string& x) { cout << x; }
void pr(const char* x) { cout << x; }
void pr(const char* x, size_t len) { cout << string(x, len); }
void ps() { cout << endl; }
void pn() { /*do nothing*/ }
void pw() { pr(" "); }
void pc() {
    pr("]");
    ps();
}
Tp2 void pr(const pair<T1, T2>& x) {
    pr(x.ff);
    pw();
    pr(x.ss);
}
Tp void pr(const T&);
bool parse(const char* t) {
    if (t == e) return true;
    return false;
}
Tp bool parse(T&& t) { return false; }
Tp2 bool parsepair(const pair<T1, T2>& x) { return true; }
Tp bool parsepair(T&& t) { return false; }
Tp2 void psa(T1&& a, T2 t) {
    for (int i = 0; i < t; i++) pr(a[i]), pw();
    ps();
}
Tp2 void pna(T1&& a, T2 t) {
    for (int i = 0; i < t; i++) pr(a[i]), ps();
}
Tp2 void psa2(T1&& a, T2 t1, T2 t2) {
    for (int i = 0; i < t1; i++) {
        for (int j = 0; j < t2; j++) pr(a[i][j]), pw();
        ps();
    }
}
Tp void pr(const T& x) {
    bool fst = 1;
    bool op = 0;
    if (parsepair(*x.begin())) op = 1;
    for (const auto& a : x) {
        if (!fst) pw();
        if (op) pr("{");
        pr(a), fst = 0;
        if (op) pr("}");
    }
}
Tps void pr(const T& t, const Ts&... ts) {
    pr(t);
    pr(ts...);
}
Tps void ps(const T& t, const Ts&... ts) {
    pr(t);
    if (sizeof...(ts)) {
        if (!parse(t)) pw();
    }
    ps(ts...);
}
Tp void pn(const T& t) {
    for (const auto& a : t) ps(a);
}
Tps void pw(const T& t, const Ts&... ts) {
    pr(t);
    if (sizeof...(ts)) pw();
    pw(ts...);
}
Tps void pc(const T& t, const Ts&... ts) {
    bool op = 0;
    if (parsepair(t)) op = 1;
    if (op) pr("{");
    pr(t);
    if (op) pr("}");
    if (sizeof...(ts)) pr(", ");
    pc(ts...);
}
namespace trace {
#define tr(x...) pr("[", #x, "] = ["), pc(x);
#define tra(x, y...) __f0(#x, x, y)
#define tran(x, n) __fn(n, #x, x)  // TO DO~ variadic multidimensional
Tp2 void __f(const char* name, const T1& x, const T2& y) {
    pr("[", y, "] = ");
    ps(x);
}
Tps2 void __f(const char* name, const T1& x, const T2& y, const Ts&... rest) {
    const char* open = strchr(name, '[');
    pr("[", y, "]");
    __f(open + 1, x, rest...);
}
Tps2 void __f0(const char* name, const T1& x, const T2& y, const Ts&... rest) {
    const char* open = strchr(name, '[');
    pr(name, size_t(open - name));
    __f(name, x, y, rest...);
}
Tp void __fn(int n, const char* name, const T& x) {
    for (int i = 0; i < n; i++) pr(name), __f(name, x[i], i);
}
}  // namespace trace
}  // namespace output
using namespace maxmin;
using namespace input;
using namespace output;
using namespace output::trace;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e3 + 5;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const string dir = "DLRU";

int a[N][N], n, m, k, d[N][N];

void bfs(pii root) {
    queue<pii> q;
    q.push(root);
    d[root.ff][root.ss] = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.ff + dx[i];
            int y = cur.ss + dy[i];
            cout << x << " " << y << endl;
            if (d[x][y] > d[cur.ff][cur.ss] + 1 and a[x][y]) {
                d[x][y] = d[cur.ff][cur.ss] + 1;
                q.push({x, y});
            }
        }
    }
}

int32_t main() {
    IOS;
    int i, j;
    pii st;
    re(n, m, k);

    if (k & 1) return ps("IMPOSSIBLE"), 0;

    for (i = 0; i <= n + 1; i++)
        for (j = 0; j <= m + 1; j++)
            d[i][j] = INF;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            char c;
            re(c);
            if (c == 'X') st.ff = i, st.ss = j, a[i][j] = 1;
            if (c == '.') a[i][j] = 1;
        }
    }

    bfs(st);

    int x = st.ff, y = st.ss;
    string ans;
    while (k--) {
        for (i = 0; i < 4; i++) {
            int p = x + dx[i], q = y + dy[i];
            if (d[p][q] > k) continue;
            ans += dir[i];
            x = p;
            y = q;
            break;
        }
        if (i == 4) return ps("IMPOSSIBLE"), 0;
    }
    ps(ans);
    return 0;
}
// is a bruteforce possible?
// think greedier, make more assumptions
// stuck for more than 5 minutes? move on