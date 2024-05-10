// Meysam Aghighi
//  The idea is that the crazy driver tries to waste time in the best possible
//  place (closest pair of gates) when he kcurr_times that he will need to waste time anyway.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, curr_time = 0;
    long long travel = 0;
    cin >> n;
    int cost[n], time[n], best_wait[n];  // best_wait[i] = best place (travelance) to waste time before gate i
    for (int i = 1; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++)
        cin >> time[i];
    best_wait[1] = cost[1];
    for (int i = 2; i < n; i++)
        best_wait[i] = min(best_wait[i - 1], cost[i]);
    for (int i = 1; i < n; i++) {
        travel += cost[i];
        curr_time++;
        if (curr_time < time[i]) {
            long long wait_interval = time[i] - curr_time;
            if (wait_interval % 2 != 0)
                wait_interval++;
            curr_time += wait_interval;
            travel += wait_interval * best_wait[i];
        }
    }
    cout << travel << "\n";
    return 0;
}