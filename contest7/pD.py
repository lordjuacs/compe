from collections import deque

INF = int(1e9)
MAX_SIZE = 1001
n, m, k = map(int, input().split())
begin = [-1, -1]
if k % 2 != 0:
    print("IMPOSSIBLE")
else:
    d = [[INF for i in range(MAX_SIZE)] for j in range(MAX_SIZE)]
    a = [[False for i in range(MAX_SIZE)] for j in range(MAX_SIZE)]
    for i in range(1, n + 1):
        for j, c in enumerate(input()):
            if c == "X":
                begin = [i, j + 1]
                a[i][j + 1] = True
            if c == ".":
                a[i][j + 1] = True
    q = deque()
    q.append(begin)
    d[begin[0]][begin[1]] = 0
    while q:
        current = q.popleft()
        for dx, dy in [[1, 0], [0, -1], [0, 1], [-1, 0]]:
            x = current[0] + dx
            y = current[1] + dy
            if d[x][y] > d[current[0]][current[1]] + 1 and a[x][y]:
                d[x][y] = d[current[0]][current[1]] + 1
                q.append([x, y])
    x = begin[0]
    y = begin[1]
    flag = True
    while k:
        for dx, dy, c in [[1, 0, "D"], [0, -1, "L"], [0, 1, "R"], [-1, 0, "U"]]:
            i = x + dx
            j = y + dy
            if d[i][j] <= k:
                print(c, end="")
                x = i
                y = j
                flag = False
                break
        if flag:
            print("IMPOSSIBLE")
            break
        k -= 1
