#include <bits/stdc++.h>
using namespace std;

long long int check(long long int k, long long int mid) {
    long long int emoji_sum;
    if (mid <= k)
        emoji_sum = mid * (mid + 1) / 2;
    else {
        long long int curr_sum = 2 * k - mid - 1;
        emoji_sum = k * k - (curr_sum) * (curr_sum + 1) / 2;
    }
    return emoji_sum;
}
int main() {
    int t;
    long long int x, mid, emoji_sum, left, right, k;
    cin >> t;
    while (t--) {
        cin >> k >> x;
        left = 1;
        right = 2 * k - 1;
        while (left < right) {
            mid = (left + right) / 2;
            emoji_sum = check(k, mid);
            if (emoji_sum >= x)
                right = mid;
            else
                left = mid + 1;
        }
        cout << right << "\n";
    }
}