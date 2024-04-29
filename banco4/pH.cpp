#include <bits/stdc++.h>
using namespace std;

long long int n, m, k;

long long int rest_pillows(long long int hobbits, long long int frodo_pillows) {
    long long int tot_pillows_rest = (frodo_pillows - 1) * frodo_pillows / 2;  // sum of 1 to frodo_pillows - 1 (difference is max 1)

    if (hobbits < (frodo_pillows - 1)) {  // hobbits sad if frodo has 2 or more pillows
        long long int shortage = (frodo_pillows - 1) - hobbits;
        tot_pillows_rest -= shortage * (shortage + 1) / 2;
    } else if (hobbits > (frodo_pillows - 1)) {  // more hobbits than pillows
        tot_pillows_rest += hobbits - (frodo_pillows - 1);
    }

    return tot_pillows_rest;
}

long long int find_frodo(long long int left, long long int right) {
    long long int max_frodo_pillows, mid, left_rest, right_rest;

    while (left <= right) {
        mid = (left + right) / 2;
        left_rest = rest_pillows(k - 1, mid);
        right_rest = rest_pillows(n - k, mid);

        if ((left_rest + mid + right_rest) <= m) {
            left = mid + 1;
            max_frodo_pillows = mid;
        } else {
            right = mid - 1;
        }
    }

    return max_frodo_pillows;
}

int main() {
    cin >> n >> m >> k;

    cout << find_frodo(1, m) << "\n";

    return 0;
}