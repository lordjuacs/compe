n = int(input())
dist = [[] for i in range(n)]
for i in range(n):
    dist[i] = list(map(int, input().split()))


todel = list(map(int, input().split()))
ans = [0] * n
seen = [False] * n

for k in range(n - 1, -1, -1):
    sum = 0
    realk = todel[k] - 1
    seen[realk] = True
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j], dist[i][realk] + dist[realk][j])
            if seen[i] and seen[j]:
                sum += dist[i][j]
    ans[k] = sum

print(" ".join(map(str, ans)))
