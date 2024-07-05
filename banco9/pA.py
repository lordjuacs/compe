import math

t = int(input())
while t:
    n = int(input())
    print(int(100 / math.gcd(100, n)))
    t -= 1
