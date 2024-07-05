#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int res = 1;
    long long int t = n;
    for (int i = 0; i < 5; i++) {
        res *= n;
        n -= 1;
    }
    res /= 120;
    for (int i = 0; i < 5; i++) {
        res *= t;
        t -= 1;
    }
    cout << res << endl;
    return 0;
}