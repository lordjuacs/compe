n = int(input())
tot = 1
res = 1
problems = list(map(int, input().split()))
for i in range(n - 1):
    if problems[i] * 2 >= problems[i + 1]:
        tot += 1
    else:
        res = max(res, tot)
        tot = 1
print(max(res, tot))
