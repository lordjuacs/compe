#include <bits/stdc++.h>
using namespace std;
/*
You are given a tetrahedron. Let's mark its vertices with letters A, B, C and D correspondingly.
An ant is standing in the vertex D of the tetrahedron. The ant is quite active and he wouldn't stay idle. At each moment of time he makes a step from one vertex to another one along some edge of the tetrahedron. The ant just can't stand on one place.
You do not have to do much to solve the problem: your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself. As the number can be quite large, you should prlong long int it modulo 1000000007 (109 + 7).




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
    long long int tot = 100001;
    vector<long long int> count(tot, 0);
    long long int n, x;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
        cin >> x;
        count[x]++;
    }

    vector<long long int> dp(tot, 0);
    dp[0] = 0;
    dp[1] = count[1];
    for (long long int i = 2; i <= tot; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
    cout << dp[tot] << "\n";
    return 0;
}