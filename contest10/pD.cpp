#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> max_sum, prefix_sum, suffix_sum, sum;
vector<ll> arr;
ll n;

ll merge_max_sum(ll left_max_sum, ll right_max_sum, ll left_suffix_sum, ll right_prefix_sum) {
    return max({left_max_sum, right_max_sum, left_suffix_sum + right_prefix_sum});
}

void merge(ll node) {
    sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
    prefix_sum[node] = max(prefix_sum[2 * node + 1], sum[2 * node + 1] + prefix_sum[2 * node + 2]);
    suffix_sum[node] = max(suffix_sum[2 * node + 2], sum[2 * node + 2] + suffix_sum[2 * node + 1]);
    max_sum[node] = merge_max_sum(max_sum[2 * node + 1], max_sum[2 * node + 2], suffix_sum[2 * node + 1], prefix_sum[2 * node + 2]);
}

void build_tree(ll node, ll start, ll end) {
    if (start == end) {
        max_sum[node] = prefix_sum[node] = suffix_sum[node] = sum[node] = arr[start];
    } else {
        ll mid = (start + end) / 2;
        build_tree(2 * node + 1, start, mid);
        build_tree(2 * node + 2, mid + 1, end);
        merge(node);
    }
}

void query(ll node, ll start, ll end, ll left, ll right, ll &res_max_sum, ll &res_prefix_sum, ll &res_suffix_sum, ll &res_sum) {
    if (left > end || right < start) {
        res_max_sum = res_prefix_sum = res_suffix_sum = res_sum = 0;
        return;
    }
    if (left <= start && right >= end) {
        res_max_sum = max_sum[node];
        res_prefix_sum = prefix_sum[node];
        res_suffix_sum = suffix_sum[node];
        res_sum = sum[node];
        return;
    }
    ll mid = (start + end) / 2;
    ll left_max_sum, left_prefix_sum, left_suffix_sum, left_sum;
    ll right_max_sum, right_prefix_sum, right_suffix_sum, right_sum;
    query(2 * node + 1, start, mid, left, right, left_max_sum, left_prefix_sum, left_suffix_sum, left_sum);
    query(2 * node + 2, mid + 1, end, left, right, right_max_sum, right_prefix_sum, right_suffix_sum, right_sum);
    res_sum = left_sum + right_sum;
    res_prefix_sum = max(left_prefix_sum, left_sum + right_prefix_sum);
    res_suffix_sum = max(right_suffix_sum, right_sum + left_suffix_sum);
    res_max_sum = merge_max_sum(left_max_sum, right_max_sum, left_suffix_sum, right_prefix_sum);
}

void update(ll node, ll start, ll end, ll idx, ll val) {
    if (start == end) {
        arr[idx] = val;
        max_sum[node] = prefix_sum[node] = suffix_sum[node] = sum[node] = val;
    } else {
        ll mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        merge(node);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    arr.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll tree_size = 4 * n;
    max_sum.resize(tree_size);
    prefix_sum.resize(tree_size);
    suffix_sum.resize(tree_size);
    sum.resize(tree_size);

    build_tree(0, 0, n - 1);

    for (ll i = 0; i < q; ++i) {
        ll k, u;
        cin >> k >> u;
        update(0, 0, n - 1, k - 1, u);
        ll res_max_sum, res_prefix_sum, res_suffix_sum, res_sum;
        query(0, 0, n - 1, 0, n - 1, res_max_sum, res_prefix_sum, res_suffix_sum, res_sum);
        cout << max(res_max_sum, 0LL) << endl;
    }

    return 0;
}
