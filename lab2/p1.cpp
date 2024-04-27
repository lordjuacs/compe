#include <bits/stdc++.h>

using namespace std;

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
    int op;
    int v;

    while (cin >> n) {
        stack<int> s;
        priority_queue<int> pq;
        queue<int> q;
        bool f = false, sv = true, pqv = true, qv = true;
        for (int i = 0; i < n; i++) {
            cin >> op >> v;
            if (op == 1) {
                s.push(v);
                pq.push(v);
                q.push(v);
            } else {
                if (s.empty()) {
                    f = true;
                    for (++i; i < n; i++) {
                        cin >> op >> v;
                    }
                    sv = pqv = qv = 0;

                    break;
                } else {
                    // if front/top of structure is not equal to v, then it cannot be any of them
                    if (s.top() != v) {
                        sv = false;
                    }
                    if (q.front() != v) {
                        qv = false;
                    }
                    if (pq.top() != v) {
                        pqv = false;
                    }
                    s.pop();
                    q.pop();
                    pq.pop();
                }
            }
        }
        int sum = sv + pqv + qv;
        if (sum > 1)
            cout << "not sure" << endl;
        else if (sum == 0)
            cout << "impossible" << endl;
        else
            cout << (sv ? "stack" : qv ? "queue"
                                : pqv  ? "priority queue"
                                       : "impossible")
                 << endl;
    }

    return 0;
}
