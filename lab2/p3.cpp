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
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool bmax[n], bmin[n];
    long long left_max = -INFINITY, right_min = INFINITY;
    for (long long i = 0; i < n; i++) {
        if (left_max <= a[i]) {
            bmin[i] = true;
            if (left_max < a[i])
                left_max = a[i];
        } else
            bmin[i] = false;
    }
    for (long long i = n - 1; i >= 0; i--) {
        if (right_min >= a[i]) {
            bmax[i] = true;
            if (right_min > a[i])
                right_min = a[i];
        } else
            bmax[i] = false;
    }
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        if (bmin[i] && bmax[i])
            count++;
    }
    cout << count << endl;
    return 0;
}