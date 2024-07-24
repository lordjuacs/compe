#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Get input
    int N;
    scanf("%d\n", &N);
    std::vector<int> values(N);
    std::vector<char> suits(N);
    scanf("%c%d", &suits[0], &values[0]);
    for (int i = 1; i < N; i++) {
        scanf(" %c%d", &suits[i], &values[i]);
    }

    // Go over all valid suit permutations
    int best_lis = 0;
    vector<char> suit_order{'E', 'R', 'S', 'W', 'C'};
    do {
        // Translate the hand to integers with the same relative order
        vector<int> hand(N);
        for (int i = 0; i < N; i++) {
            hand[i] = N * (find(suit_order.begin(), suit_order.end(), suits[i]) - suit_order.begin()) + values[i];
        }
        int SUPERIOR = 6 * N;

        // Compute LIS (longest increasing subsequence)
        vector<int> lis_aux(hand.size() + 1, SUPERIOR);  // position i will contain the smallest value that ends an increasing subsequence of length i+1 (or SUPERIOR if no such sequence exists)
        for (auto i = hand.begin(); i < hand.end(); i++) {
            auto j = upper_bound(lis_aux.begin(), lis_aux.end(), *i);
            *j = *i;
        }
        int lis = find(lis_aux.begin(), lis_aux.end(), SUPERIOR) - lis_aux.begin();

        // Take the best LIS over all suit orders
        best_lis = max(best_lis, lis);
    } while (next_permutation(suit_order.begin(), suit_order.end() - 1));

    // All cards not in the LIS should be moved
    printf("%d\n", N - best_lis);

    return 0;
}
