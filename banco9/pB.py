import math


def simple(num, den):
    gcd = math.gcd(num, den)
    return (num // gcd, den // gcd)


def solve(a, b, c, d):
    a, b = simple(a, b)
    c, d = simple(c, d)
    if a == c and b == d:
        return 0
    if a == 0 or c == 0:
        return 1 if a == 0 or c == 0 else 2
    lcm_den = abs(b * d) // math.gcd(b, d)

    new_a = a * (lcm_den // b)
    new_c = c * (lcm_den // d)

    if new_a == new_c:
        return 0

    if new_a % new_c == 0 or new_c % new_a == 0:
        return 1
    return 2


t = int(input())
while t:
    a, b, c, d = map(int, input().split())
    print(solve(a, b, c, d))
    t -= 1
