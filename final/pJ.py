n, p = map(int, input().split())
inout = [0] * n
for k in range(n - 1):
    a, b = map(int, input().split())
    inout[a] += 1
    inout[b] += 1
leaf_nodes = inout.count(1)
print(2 * (p // leaf_nodes) + min(2, p % leaf_nodes))
