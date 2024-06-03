n = int(input())
health = list(map(int, input().split()))
left = [0] * n
right = [0] * n
for i in range(n):
    left[i] = health[i] + n - i - 1
    right[i] = health[i] + i
for i in range(1, n):
    left[i] = max(left[i], left[i - 1])
for i in range(n - 2, -1, -1):
    right[i] = max(right[i], right[i + 1])
min_power = 3e9
for i in range(n):
    h = health[i]
    if i > 0:
        h = max(h, left[i - 1])
    if i + 1 < n:
        h = max(h, right[i + 1])
    min_power = min(min_power, h)
print(min_power)
