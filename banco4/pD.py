def find_x(l, r, a):
    if l == r:
        return r
    if r % a != (a - 1):
        x = ((r // a) * a) - 1
        if x >= l:
            return x
    return r


t = int(input())
while t:
    l, r, a = map(int, input().split())
    x = find_x(l, r, a)
    func = (x // a) + (x % a)
    print(func)
    t -= 1
