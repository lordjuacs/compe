#include <bits/stdc++.h>
using namespace std;

long double check(long double a, long double b) {
    return sqrt(a * a + b * b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    long int x1, y1, x2, y2;
    long int vmax, t;
    long int vx, vy, wx, wy;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy >> wx >> wy;
    long double left = 1e-9;
    long double right = 1e9;
    long double time = 0;
    long double x;
    long double y;
    int n = 100000;
    while (n--) {
        time = (left + right) / 2;

        if (time <= t) {
            x = x1 + vx * time;
            y = y1 + vy * time;
        } else {
            x = x1 + vx * t + wx * (time - t);
            y = y1 + vy * t + wy * (time - t);
        }
        if (check(x - x2, y - y2) <= vmax * time) {
            right = time;
        } else {
            left = time;
        }
    }
    cout << fixed << setprecision(18) << time << endl;

    return 0;
}