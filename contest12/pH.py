n, w = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if w > n:
    print(0)
elif w == 1:
    print(n)
else:
    diff_a = [a[i + 1] - a[i] for i in range(n - 1)]
    diff_b = [b[i + 1] - b[i] for i in range(w - 1)]
    all_diff = diff_b + [-1e9] + diff_a
    kmp = [0] * len(all_diff)
    can_see = 0
    for i in range(1, len(all_diff)):
        j = kmp[i - 1]
        while j > 0 and all_diff[i] != all_diff[j]:
            j = kmp[j - 1]
        if all_diff[i] == all_diff[j]:
            j += 1
        kmp[i] = j
        if kmp[i] == w - 1:
            can_see += 1
    print(can_see)
