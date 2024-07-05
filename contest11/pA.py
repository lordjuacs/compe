s = input()
n = int(input())
p = 31
f = 1
mod = 10**18 + 7
h = [0] * (len(s))
h[0] = ord(s[0]) - 96
for i in range(1, len(s)):
    f = (f * p) % mod
    h[i] = (h[i - 1] + (ord(s[i]) - 96) * f) % mod
for _ in range(n):
    L, R = map(int, input().split())
    hl_1 = h[L - 1] if L > 0 else 0
    print(((h[R - 1] - hl_1) * pow(pow(p, L, mod), -1, mod)) % mod)
