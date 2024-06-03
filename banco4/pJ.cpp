
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, k;
    std::vector<int> array(3000);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> array[i];
        int cost = 3001;
        int min_a = array[0];
        for (int d = 1; d <= min_a; d++) {
            int min_ai_pi = d;
            int max_ai_pi = -1;
            for (int i = 0; i < n; i++) {
                int pi = k;
                pi = min(k, array[i] / d);
                int ai_pi = array[i] / pi;
                max_ai_pi = max(max_ai_pi, ai_pi);
            }
            cost = min(max_ai_pi - min_ai_pi, cost);
        }
        cout << cost << "\n";
    }
    return 0;
}