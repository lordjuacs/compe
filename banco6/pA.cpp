#include <bits/stdc++.h>
using namespace std;
/*
Implement a solution to the classic knapsack problem. You are given a knapsack that can hold up to a certain weight (its capacity), and several items you may choose to put in the knapsack. Each item has a weight and a value. Choose a subset of the items (which could be all of them, or none of them) having the greatest value that fit into the knapsack (i.e. the sum of the weights of the items you choose must be less than or equal to the knapsack capacity).

*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    string in;
    int capacity, n;
    int t = 2;
    while (getline(cin, in)) {
        stringstream ss(in);
        ss >> capacity >> n;
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        vector<int> w(n + 1), v(n + 1);
        w[0] = 0;
        v[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> v[i] >> w[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (w[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        vector<int> chosenItems;
        int i = n, j = capacity;
        while (i > 0 && j > 0) {
            if (dp[i][j] != dp[i - 1][j]) {
                chosenItems.push_back(i);
                j -= w[i];
            }
            i--;
        }
        cout << chosenItems.size() << "\n";
        for (int k = chosenItems.size() - 1; k >= 0; k--)
            cout << chosenItems[k] - 1 << " ";
        cout << "\n";
        getline(cin, in);
    }
    return 0;
}