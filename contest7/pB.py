def dfs(c, adj, used, ans):
    if used[c]:
        return False
    used[c] = True
    ans += chr(ord("a") + c)
    if len(adj[c]) == 0:
        return True
    next_c = adj[c].pop()
    adj[next_c].remove(c)
    return dfs(next_c, adj, used, ans)


t = int(input())
while t:
    s = input()
    adj = [set() for i in range(26)]

    flag = True
    for i in range(1, len(s)):
        u = ord(s[i]) - ord("a")
        v = ord(s[i - 1]) - ord("a")
        adj[u].add(v)
        adj[v].add(u)
        if len(adj[u]) > 2 or len(adj[v]) > 2:
            print("NO")
            flag = False
            break

    if not flag:
        t -= 1
        continue

    used = [False] * 26
    ans = []

    for i in range(26):
        if len(adj[i]) == 1 and not dfs(i, adj, used, ans):
            print("NO")
            flag = False
            break

    if not flag:
        t -= 1
        continue

    for i in range(26):
        if len(adj[i]) > 0:
            print("NO")
            flag = False
            break

    if not flag:
        t -= 1
        continue

    print("YES")
    for i in range(26):
        if used[i] == 0:
            ans += chr(ord("a") + i)

    print("".join(ans))
    t -= 1
