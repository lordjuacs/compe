from math import gcd


def fraction(n, d):
    g = gcd(n, d)
    n //= g
    d //= g
    return (n, d)


def fraction_to_string(n, d):
    return str(n) if d == 1 else f"{n}/{d}"


def max_fraction(f1, f2):
    n1, d1 = f1
    n2, d2 = f2
    if n1 * d2 != n2 * d1:
        return f1 if n1 * d2 > n2 * d1 else f2
    else:
        return f1 if (n1 % d1) * d2 > (n2 % d2) * d1 else f2


def distance(H, x, z):
    n = H[z] - H[x + 1]
    d = H[x] - H[x + 1]
    return fraction((z - x - 1) * d + n, d)


def score(H):
    N = len(H)
    best = fraction(0, 1)
    front = [-1] * N
    c = -1

    for i in range(N):
        while c >= 0 and H[i] > H[front[c]]:
            c -= 1
        if c != -1:
            best = max_fraction(best, distance(H, front[c], i))
        c += 1
        front[c] = i

    return best


N = int(input())
H = list(map(int, input().split()))

f = score(H)
H.reverse()
f = max_fraction(f, score(H))

print(fraction_to_string(*f))
