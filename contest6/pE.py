twos = {}
rep = {}
twos[0] = 1
for i in range(1, 30):
    twos[i] = 2 * twos[i - 1]
m = int(input())
for i in range(m):
    op, val = map(int, input().split())
    if op == 1:
        if twos[val] in rep:
            rep[twos[val]] += 1
        else:
            rep[twos[val]] = 1
    else:
        for j in range(29, -1, -1):
            if val >= twos[j] and val:
                if twos[j] in rep:
                    val -= min(val // twos[j], rep[twos[j]]) * twos[j]
        if not val:
            print("YES")
        else:
            print("NO")
