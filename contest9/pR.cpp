#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, i = 0;
    cin >> n;
    n %= 360;
    if (n < 0)
        n += 360;
    ll a = 45;
    ll b = 315;
    while ((n > a) && (n < b)) {
        n -= 90;
        i++;
        if (n < 0)
            n += 360;
    }
    cout << i << "\n";
    return 0;
}
