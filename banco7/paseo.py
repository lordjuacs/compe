import heapq
from collections import deque

p, t = map(int, input().split())

adj = [[] for _ in range(p)]
all = {x: {} for x in range(p)}
for _ in range(t):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))
    if b not in all[a] or all[a][b] > c:
        all[a][b] = c
        all[b][a] = c


def dijkstra(s):
    dist = [float("inf")] * p
    parent = [None] * p
    seen = [False] * p

    dist[s] = 0

    pq = [(0, s)]

    while pq:
        d, u = heapq.heappop(pq)

        if seen[u]:
            continue
        seen[u] = True

        for v, weight in adj[u]:
            if not seen[v]:
                if dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
                    parent[v] = [u]
                    heapq.heappush(pq, (dist[v], v))
                elif dist[u] + weight == dist[v]:
                    parent[v].append(u)

    # if dist[p - 1] == float("inf"):
    #     return dist, [-1]

    seen = [False] * p
    q = deque([p - 1])
    tot = 0
    while q:
        u = q.popleft()
        if seen[u]:
            continue
        seen[u] = True
        if not parent[u]:
            continue
        for v in parent[u]:
            q.append(v)
            tot += all[u][v]

    return 2 * tot


print(dijkstra(0))
