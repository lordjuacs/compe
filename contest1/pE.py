n = int(input())
t = list(map(int, input().split()))

d = 0
tmax = 100
for i in range(n - 2):
    twodays = max(t[i], t[i + 2])
    if twodays < tmax:
        d = i
        tmax = twodays
print(f"{d + 1} {tmax}")
