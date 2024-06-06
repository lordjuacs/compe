import heapq

n, m = map(int, input().split())

adj = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

# for a in range(1, len(adj)):
#     print(a, adj[a])


def dijkstra(s):
    dist = [float("inf")] * (n + 1)
    parent = [None] * (n + 1)
    visited = [False] * (n + 1)

    dist[s] = 0

    pq = [(0, s)]

    while pq:
        d, u = heapq.heappop(pq)

        if visited[u]:
            continue
        visited[u] = True

        for v, weight in adj[u]:
            if not visited[v] and dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                parent[v] = u
                heapq.heappush(pq, (dist[v], v))

    if dist[n] == float("inf"):
        return dist, [-1]

    path = []
    i = n
    while i is not None:
        path.append(i)
        i = parent[i]

    path.reverse()
    return dist, path


s = 1
distances, path = dijkstra(s)

print(" ".join(map(str, path)))
