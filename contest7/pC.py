t = int(input())
while t:
    n, m = map(int, input().split())
    adj = [[] for i in range(n + 1)]
    for i in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    node = -1
    y = -1
    for i in range(1, n + 2):
        if len(adj[i]) == 1:
            node = adj[i][0]
            y = len(adj[adj[i][0]]) - 1
            break
    x = -1
    for a in adj[node]:
        temp = len(adj[a])
        x = max(x, temp)
    print(f"{x} {y}")
    t -= 1
