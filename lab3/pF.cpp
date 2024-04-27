#include <bits/stdc++.h>
using namespace std;

vector<int> nums(5, 0);

bool check(int i, int sum) {
    if (i == 5) return sum == 23;
    return check(i + 1, sum + nums[i]) || check(i + 1, sum - nums[i]) || check(i + 1, sum * nums[i]);
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

    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4]) {
        if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0 && nums[3] == 0 && nums[4] == 0) break;
        sort(nums.begin(), nums.end());
        bool flag = false;
        do {
            if (check(1, nums[0])) {
                cout << "Possible\n";
                flag = true;
                break;
            }
        } while (next_permutation(nums.begin(), nums.end()));
        if (!flag) cout << "Impossible\n";
    }
    return 0;
}