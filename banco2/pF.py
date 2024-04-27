t = int(input())
while t:
    n = int(input())
    val = list(map(int, input().split()))
    if n == 1:
        print(-1)
        t -= 1
        continue
    pos = list(range(1, n + 1))
    for i in range(n - 1):
        if val[i] == pos[i]:
            temp = pos[i]
            pos[i] = pos[i + 1]
            pos[i + 1] = temp
    if val[-1] == pos[-1]:
        temp = pos[-1]
        pos[-1] = pos[-2]
        pos[-2] = temp
    print(*pos)
    t -= 1
