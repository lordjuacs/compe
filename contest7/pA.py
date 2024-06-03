from collections import deque

INF = int(1e10)
MAX_TIME = 3600
MIN_TIME = 0
p = int(input())
while p:
    n, t = map(int, input().split())
    b = list(map(int, input().split()))
    arr = [INF] * (MAX_TIME + 1)
    arr[0] = 0
    q = deque()
    q.append(0)
    while len(q):
        curr = q.popleft()
        for bi in b:
            new = min(MAX_TIME, max(MIN_TIME, curr + bi))
            if arr[new] > arr[curr] + 1:
                arr[new] = arr[curr] + 1
                q.append(new)
    for i in range(t, MAX_TIME + 1):
        if arr[i] != INF:
            print(arr[i], i - t)
            break
    p -= 1
