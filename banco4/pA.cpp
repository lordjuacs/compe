#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;

    long int n, key;
    cin >> n;
    vector<int> arr(n);
    for (long int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> key;

    long int left = 0;
    long int right = n - 1;
    bool flag = true;

    while (left <= right) {
        long int piv = (left + right) / 2;
        if (arr[piv] == key) {
            cout << piv << "\n";
            flag = false;
            break;
        } else if (arr[piv] < key) {
            left = piv + 1;
        } else {
            right = piv - 1;
        }
    }

    if (flag) {
        cout << -1 << "\n";
    }

    return 0;
}