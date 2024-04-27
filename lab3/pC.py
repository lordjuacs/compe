n, s, r = map(int, input().split())
teams = [1] * n
s = list(map(int, input().split()))
for i in s:
    teams[i - 1] = 0
r = list(map(int, input().split()))
for i in r:
    teams[i - 1] += 1
for i in range(n):
    if teams[i] == 2:
        if i != 0 and teams[i - 1] == 0:
            teams[i] = 1
            teams[i - 1] = 1
        elif i != (n - 1) and teams[i + 1] == 0:
            teams[i] = 1
            teams[i + 1] = 1
print(teams.count(0))
