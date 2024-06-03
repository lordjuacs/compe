n = int(input())
costs = [0] + list(map(int, input().split()))
TOT = 30000
dp = [0] + [-1] * (TOT)
for j in range(1, n + 1):
    for i in range(TOT + 1 - costs[j]):
        if dp[i] > -1:
            if dp[i + costs[j]] == -1:
                dp[i + costs[j]] = j
            else:
                dp[i + costs[j]] = -2
        elif dp[i] == -2:
            dp[i + costs[j]] = -2
m = int(input())
ss = list(map(int, input().split()))
for s in ss:
    if dp[s] == -1:
        print("Impossible")
    elif dp[s] == -2:
        print("Ambiguous")
    else:
        res = []
        while s:
            res.append(dp[s])
            s -= costs[dp[s]]
        for i in range(len(res) - 1, -1, -1):
            print(res[i], end=" ")
        print()
