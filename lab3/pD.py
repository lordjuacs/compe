t = int(input())
ans = []
while t:
    length = int(input())
    p = int(input())
    bars = list(map(int, input().split()))

    sol = [[0 for j in range(length + 1)] for i in range(p + 1)]
    for i in range(p + 1):
        sol[i][0] = True
    for j in range(1, length + 1):
        sol[0][j] = False
    for i in range(1, p + 1):
        for j in range(1, length + 1):
            # j: current sum, i-1: current bar
            # if current sum is less than current bar, then we can't include current bar, use the logic from previous bar
            if j < bars[i - 1]:
                sol[i][j] = sol[i - 1][j]
            else:  # j >= bars[i - 1]: else, we can either include or exclude the current bar. if included, check if the previous sum is possible with previous bars
                sol[i][j] = sol[i - 1][j] or sol[i - 1][j - bars[i - 1]]
    ans.append("YES" if sol[p][length] else "NO")
    t -= 1
for a in ans:
    print(a)
