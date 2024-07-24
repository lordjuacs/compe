def check(graph, valid, seen, curr):
    for next in graph[curr]:
        if not seen[next]:
            seen[next] = True
            if valid[next] == -1 or check(graph, valid, seen, valid[next]):
                valid[next] = curr
                return True
    return False


def find_min(tot, graph):
    valid = [-1] * tot
    seen = [False] * tot

    for curr in range(tot):
        seen = [False] * tot
        check(graph, valid, seen, curr)

    return sum(1 for m in valid if m != -1) // 2


n, m = map(int, input().split())
tot = n + m
graph = [[] for i in range(tot)]
for i in range(n):
    ki = int(input())
    line = list(map(int, input().split()))
    for j in line:
        graph[i].append(n + j - 1)
        graph[n + j - 1].append(i)

print(find_min(tot, graph))
