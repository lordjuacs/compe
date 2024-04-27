t = int(input())
while t:
    d = set()
    balloons = 0
    n = int(input())
    s = input()
    for c in range(n):
        if s[c] not in d:
            d.add(s[c])
            balloons += 2
        else:
            balloons += 1
    print(balloons)
    t -= 1
