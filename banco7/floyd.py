import heapq

n, m = map(int, input().split())

adj = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))


def floyd():
    dist = [[float("inf")] * (n + 1) for _ in range(n + 1)]
    prev = [[None] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dist[i][i] = 0
        prev[i][i] = i
    for i in range(1, n + 1):
        for j, w in adj[i]:
            dist[i][j] = w
            prev[i][j] = i
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    prev[i][j] = prev[k][j]
    min_cost = float("inf")
    for i in range(1, n + 1):
        total_cost = sum(
            dist[i][j] for j in range(1, n + 1) if dist[i][j] < float("inf")
        )
        min_cost = min(min_cost, total_cost)

    return min_cost


print(floyd())
