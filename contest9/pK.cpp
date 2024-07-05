#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int sugerir = (n + 2) / 1 * (n + 1) / 2 * n / 3;
    long long int error = (n + 4) / 1 * (n + 3) / 2 * (n + 2) / 3 * (n + 1) / 4 * n / 5;
    cout << error * sugerir << endl;
    return 0;
}