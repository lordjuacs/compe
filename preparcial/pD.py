n, m = map(int, input().split())
tot = 0
while m > n:
    if m % 2 == 1:
        m += 1
        tot += 1
    m //= 2
    tot += 1
print(tot + n - m)
