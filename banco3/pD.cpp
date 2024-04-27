#include <bits/stdc++.h>
using namespace std;

void fill(vector<int>& cards, unordered_map<int, unordered_map<string, unordered_map<char, vector<int>>>>& results, int total_cards, int i, int j, const string& key, char op, int val) {
    if (results[total_cards - 1][key][op].size() == 0)
        results[total_cards - 1][key][op] = vector<int>();
    results[total_cards - 1][key][op].push_back(val);
    for (int other = 0; other < total_cards; other++) {
        if (other != i && other != j) {
            results[total_cards - 1][key][op].push_back(cards[other]);
        }
    }
}
void find_24(vector<int>& cards, int total_cards, unordered_map<int, unordered_map<string, unordered_map<char, vector<int>>>>& results, int v) {
    for (int i = 0; i < total_cards; i++) {
        for (int j = 0; j < total_cards; j++) {
            if (i != j) {
                string key = std::to_string(i) + std::to_string(j) + "-" + std::to_string(v);

                fill(cards, results, total_cards, i, j, key, '+', cards[i] + cards[j]);

                fill(cards, results, total_cards, i, j, key, '-', cards[i] - cards[j]);

                fill(cards, results, total_cards, i, j, key, '*', cards[i] * cards[j]);

                if (cards[j] != 0 && cards[i] % cards[j] == 0) {
                    fill(cards, results, total_cards, i, j, key, '/', cards[i] / cards[j]);
                }
            }
        }
    }
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
    vector<int> cards(4);
    cin >> n;
    for (int i = 0; i < n; i++) {
        unordered_map<int, unordered_map<string, unordered_map<char, vector<int>>>> results;
        cin >> cards[0] >> cards[1] >> cards[2] >> cards[3];

        results[4] = unordered_map<string, unordered_map<char, vector<int>>>();
        results[4]["0123"] = unordered_map<char, vector<int>>();
        results[4]["0123"]['.'] = cards;
        int v = 0;

        for (int total_cards = 4; total_cards > 1; total_cards--) {
            results[total_cards - 1] = unordered_map<string, unordered_map<char, vector<int>>>();
            for (auto& val : results[total_cards]) {
                for (auto& val2 : val.second) {
                    find_24(val2.second, total_cards, results, v++);
                }
            }
        }

        int max = 0;
        for (auto& val : results[1]) {
            for (auto& val2 : val.second) {
                for (auto& val3 : val2.second)
                    if (val3 <= 24 && val3 > max)
                        max = val3;
            }
        }
        cout << max << "\n";
    }
    return 0;
}
