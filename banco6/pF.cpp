#include <bits/stdc++.h>
using namespace std;
/*
Vasya has n days of vacations! So he decided to improve his IT skills and do sport. Vasya knows the following information about each of this n days: whether that gym opened and whether a contest was carried out in the Internet on that day. For the i-th day there are four options:

*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distlong long intos parametros aqui.

    */
    int n;
    cin >> n;
    int today, yesterday = 0, rest = 0;
    for (int i = 0; i < n; i++) {
        cin >> today;
        if ((today == 0) || (today == 1 && yesterday == 1) || (today == 2 && yesterday == 2)) {
            rest++;
            yesterday = 0;
        } else {
            if (today == 3)
                yesterday = ((yesterday < 3) ? (3 - yesterday) : yesterday);
            else
                yesterday = today;
        }
    }
    cout << rest << "\n";
    return 0;
}