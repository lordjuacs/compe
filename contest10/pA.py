def dfs(v, graph, visited):
    visited[v] = True
    for neighbor in graph[v]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited)


def reachable(n, m, edges):
    graph = [[] for _ in range(n + 1)]
    for a, b in edges:
        graph[a].append(b)
        graph[b].append(a)

    visited = [False] * (n + 1)
    dfs(1, graph, visited)

    return visited


n, m = map(int, input().split())
edges = []
for i in range(m):
    edges.append(tuple(map(int, input().split())))
connected = reachable(n, m, edges)
flag = False
for i in range(1, n + 1):
    if not connected[i]:
        print(i)
        flag = True
if not flag:
    print("Connected")
