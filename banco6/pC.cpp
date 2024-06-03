#include <bits/stdc++.h>
using namespace std;

/*
Patrick has just finished writing a message to his sweetheart Stacey when he noticed that the message didn't look fancy. Patrick was nervous while writing the message, so some of the letters there were lowercase and some of them were uppercase.

Patrick believes that a message is fancy if any uppercase letter stands to the left of any lowercase one. In other words, this rule describes the strings where first go zero or more uppercase letters, and then — zero or more lowercase letters.

To make the message fancy, Patrick can erase some letter and add the same letter in the same place in the opposite case (that is, he can replace an uppercase letter with the lowercase one and vice versa). Patrick got interested in the following question: what minimum number of actions do we need to make a message fancy? Changing a letter's case in the message counts as one action. Patrick cannot perform any other actions.
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
    // PRuvetSTAaYA
    string input;
    cin >> input;
    vector<int> dp(input.size() + 1, 0);
    for (int i = input.size() - 1; i >= 0; i--)
        dp[i] = dp[i + 1] + (input[i] >= 'a' ? 0 : 1);
    int curr_lower = 0, min_fancy = dp[0];
    for (int i = 0; i < input.size(); i++) {
        curr_lower += (input[i] >= 'a' ? 1 : 0);
        min_fancy = min(min_fancy, dp[i + 1] + curr_lower);
    }
    cout << min_fancy << "\n";
    return 0;
}
