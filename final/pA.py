import itertools
import bisect


def find_lis(cards):
    lis = []
    for c in cards:
        pos = bisect.bisect(lis, c)
        if pos == len(lis):
            lis.append(c)
        else:
            lis[pos] = c
    return len(lis)


n = int(input())
cards = [(x[0], int(x[1:])) for x in input().split()]
tot_min = n

for perm in itertools.permutations("SWER"):
    ordered = {palo: i for i, palo in enumerate(perm)}
    ordered["C"] = 4
    ordered_cards = [num + n * ordered[palo] for palo, num in cards]
    lis = find_lis(ordered_cards)
    tot_min = min(tot_min, n - lis)

print(tot_min)
