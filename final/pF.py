def score(p, e):
    min = 10
    max = 0
    sum = 10 * p
    for x in e:
        if x > max:
            max = x
        if x < min:
            min = x
        sum = sum + x
    return sum - min - max


n = int(input())
c = []
puntos = []
best = [0, 0, 0]
for i in range(n):
    line = input().split()
    c.append(line[0])
    p = int(line[1])
    e = []
    for x in line[2:]:
        e.append(int(x))
    sc = score(p, e)
    puntos.append(sc)
    if sc > best[0]:
        best[2] = best[1]
        best[1] = best[0]
        best[0] = sc
    elif sc > best[1]:
        best[2] = best[1]
        best[1] = sc
    elif sc > best[2]:
        best[2] = sc
for j in range(3):
    for i in range(n):
        if puntos[i] == best[j]:
            print(c[i] + " " + str(puntos[i]))
            puntos[i] = -1
