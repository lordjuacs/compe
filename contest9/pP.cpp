#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int main() {
    ll x1, y1, x2, y2, ans;
    cin >> x1 >> y1 >> x2 >> y2;
    ll temp = y2 - y1;
    if (temp % 2 == 0) {
        ans = (x2 - x1 + 1) * ((y2 - y1 + 2) / 2) - (x2 - x1 + 1) / 2;
    } else {
        ans = (x2 - x1 + 1) * ((y2 - y1 + 2) / 2);
    }
    cout << ans << endl;
    return 0;
}