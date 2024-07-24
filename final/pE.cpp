#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void better(ll& num, ll& den) {
    ll g = gcd(num, den);
    num /= g;
    den /= g;
}

std::pair<ll, ll> distance(const std::vector<ll>& h, int x, int z) {
    ll num = h[z] - h[x + 1];
    ll den = h[x] - h[x + 1];
    ll length = z - x - 1;
    ll num_result = length * den + num;
    better(num_result, den);
    return {num_result, den};
}

std::pair<ll, ll> punt(const std::vector<ll>& h) {
    int n = h.size();
    std::vector<int> front(n, -1);
    int c = -1;
    std::pair<ll, ll> best = {0, 1};

    for (int i = 0; i < n; ++i) {
        while (c >= 0 && h[i] > h[front[c]]) {
            --c;
        }
        if (c >= 0) {
            auto dist = distance(h, front[c], i);
            better(dist.first, dist.second);
            if (dist.first * best.second > best.first * dist.second) {
                best = dist;
            }
        }
        ++c;
        front[c] = i;
    }
    return best;
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
    int n;
    std::cin >> n;
    std::vector<ll> h(n);

    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    auto f1 = punt(h);
    std::reverse(h.begin(), h.end());
    auto f2 = punt(h);

    std::pair<ll, ll> best = (f1.first * f2.second > f2.first * f1.second) ? f1 : f2;
    std::cout << (best.second == 1 ? std::to_string(best.first) : std::to_string(best.first) + "/" + std::to_string(best.second)) << std::endl;

    return 0;
}
