import math

n, k = map(int, input().split())
requests = [-1] * n
requests[0] = int(input())
eval_req = 0
concurrent = 1
max_concurrent = concurrent
for i in range(1, n):
    requests[i] = int(input())
    concurrent += 1
    while requests[eval_req] + 1000 <= requests[i]:
        eval_req += 1
        concurrent -= 1
    if concurrent > max_concurrent:
        max_concurrent = concurrent
print(math.ceil(max_concurrent / k))
