#include <bits/stdc++.h>

using namespace std;

void fix(deque<int> &left, deque<int> &right);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    int n;
    cin >> n;
    deque<int> left, right;
    for (int i = 0; i < n; i++) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "push_back") {
            right.push_back(x);
            fix(left, right);
        } else if (op == "push_front") {
            left.push_front(x);
            fix(left, right);
        } else if (op == "push_middle") {
            if (left.size() >= right.size())
                left.push_back(x);
            else {
                int t = right.front();
                right.pop_front();
                left.push_back(t);
                right.push_front(x);
            }
            fix(left, right);

        } else {
            if (x < left.size()) {
                cout << left[x];
            } else {
                cout << right[x - left.size()];
            }
            if (i < n - 1) cout << endl;
        }
    }
    return 0;
}

void fix(deque<int> &left, deque<int> &right) {
    if (left.size() > right.size() + 1) {
        int t = left.back();
        left.pop_back();
        right.push_front(t);
    } else if (right.size() > left.size() + 1) {
        int t = right.front();
        right.pop_front();
        left.push_back(t);
    }
}