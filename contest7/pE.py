def dfs(adj, visited, cats, s, tot, m, count):
    if visited[s]:
        return
    visited[s] = True
    if cats[s]:
        tot += 1
    else:
        tot = 0
    if tot > m:
        return
    if s != 1 and len(adj[s]) == 1:
        count[0] += 1
    for i in adj[s]:
        dfs(adj, visited, cats, i, tot, m, count)
    return


n, m = map(int, input().split())
adj = [[] for i in range(n + 1)]
visited = [False] * (n + 1)
cats = [0] + list(map(int, input().split()))
for i in range(n - 1):
    x, y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)
count = [0]
dfs(adj, visited, cats, 1, 0, m, count)
print(count[0])
