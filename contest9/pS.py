import math

n, r = map(float, input().split())
x = math.pi / (2.0 * n)
y = math.pi - 3 * math.pi / (2.0 * n)
i = r
j = i * math.sin(3.1415926535897932 / (2.0 * n)) / math.sin(y)
s = 0.5 * j * r * math.sin(2 * x)
tot = n * s * 2
print("{:.12f}".format(tot))
