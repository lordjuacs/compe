dic = {}
for i in range(1, 31):
    dic[i] = []
    for j in range(1, 31):
        d = (i**j) % 10
        if d not in dic[i]:
            dic[i].append(d)

t = int(input())
while t:
    x = list(map(int, input().split()))
    a, b = x[0], x[1]
    if b == 0:
        print(1)
        t -= 1
        continue
    if a == 0:
        print(0)
        t -= 1
        continue
    d = int(b) % len(dic[int(a)])
    print(dic[int(a)][d - 1])
    t -= 1
