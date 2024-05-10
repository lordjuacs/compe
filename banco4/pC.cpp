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
    int N = 5;
    int BITS = 3;
    int nums[BITS][(int)N];
    for (int i = 0; i < BITS; i++) {
        for (int j = 0; j < N; j++) {
            nums[i][j] = 0;
        }
    }
    for (int i = 0; i < BITS; i++) {
        for (int j = 1; j < N; j++) {
            nums[i][j] = nums[i][j - 1];
            if (!((j >> i) & 1))
                nums[i][j]++;
        }
    }
    for (int i = 0; i < BITS; i++) {
        for (int j = 0; j < N; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}