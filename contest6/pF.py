mod = 1e9 + 7

t = int(input())
while t:
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    nums_tot = 0
    max_tot = 0
    curr_tot = 0
    for i in range(n):
        nums_tot += nums[i]
        curr_tot += nums[i]
        if curr_tot < 0:
            curr_tot = 0
        else:
            max_tot = max(max_tot, curr_tot)
    all_tot = nums_tot
    if max_tot > 0:
        all_tot += ((2**k) - 1) * max_tot  # % mod
    all_tot = mod
    print(all_tot)
    t -= 1
