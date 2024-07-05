def find(u, parent):
    return u if parent[u] == u else find(parent[u], parent)


def union(u, v, parent):
    uset = find(u, parent)
    vset = find(v, parent)
    parent[uset] = vset


n = int(input())
parent = [i for i in range(n + 1)]
close = []

for _ in range(n - 1):
    u, v = map(int, input().split())
    if find(u, parent) == find(v, parent):
        close.append((u, v))
    else:
        union(u, v, parent)

root = list({find(i, parent) for i in range(1, n + 1)})

t = len(close)
print(t)
for i in range(t):
    print(close[i][0], close[i][1], root[i], root[i + 1])
