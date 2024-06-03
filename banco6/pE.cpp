#include <bits/stdc++.h>
using namespace std;
/*
You are given a tetrahedron. Let's mark its vertices with letters A, B, C and D correspondingly.
An ant is standing in the vertex D of the tetrahedron. The ant is quite active and he wouldn't stay idle. At each moment of time he makes a step from one vertex to another one along some edge of the tetrahedron. The ant just can't stand on one place.
You do not have to do much to solve the problem: your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself. As the number can be quite large, you should print it modulo 1000000007 (109 + 7).




*/
long long int mod = 1000000007;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    long long int n;
    cin >> n;
    vector<vector<long long int>> dp(2, vector<long long int>(n + 1, 0));
    dp[0][0] = 0;
    dp[1][0] = 1;

    for (long long int j = 1; j <= n; j++) {
        dp[0][j] = (2 * dp[0][j - 1] + dp[1][j - 1]) % mod;
        dp[1][j] = (3 * dp[0][j - 1]) % mod;
    }
    cout << dp[1][n] << "\n";
    return 0;
}