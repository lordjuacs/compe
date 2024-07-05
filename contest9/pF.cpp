#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nCr(ll n, ll r) {
    ll s = 1;
    ll i = 1;
    while (i <= r) {
        s = s * n / i;
        i++;
        n--;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << nCr(n, 5) + nCr(n, 6) + nCr(n, 7);
    return 0;
}