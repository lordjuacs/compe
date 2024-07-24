from math import gcd


def mcm(x, y):
    return x // gcd(x, y) * y


def find(h, start, end):
    num = h[end] - h[start + 1]
    den = h[start] - h[start + 1]
    maximo = gcd(num, den)
    return end - start - 1, num // maximo, den // maximo


def punct(h):
    i = [-1] * len(h)
    t = -1
    maxtam = 0
    maxnum = 0
    maxden = 1
    for curr in range(len(h)):
        while t >= 0 and h[i[t]] < h[curr]:
            t -= 1
        if t >= 0:
            tam, tamnum, tamden = find(h, i[t], curr)
            if tam > maxtam or (tam == maxtam and tamnum * maxden < tamden * maxnum):
                maxtam = tam
                maxnum = tamnum
                maxden = tamden
        t += 1
        i[t] = curr
    return maxtam, maxnum, maxden


def pretty(n, d):
    return str(n) if d == 1 else f"{n}/{d}"


n = int(input())
h = list(map(int, input().split()))
revh = h[::-1]
a1, n1, d1 = punct(h)
a2, n2, d2 = punct(revh)

if a1 > a2:
    print(pretty(a1 * d1 + n1, d1))
elif a2 > a1:
    print(pretty(a2 * d2 + n2, d2))
elif n1 * d2 > n2 * d1:
    print(pretty(a1 * d1 + n1, d1))
elif a2 == 0:
    print(0)
else:
    print(pretty(a2 * d2 + n2, d2))
