t = int(input())
ans = []
while t:
    x = input()
    y = input()
    left = [" "] * len(x)
    right = [" "] * len(x)
    for i in range(len(x) // 2):
        a = int(x[i])
        c = int(x[len(x) - 1 - i])
        b = int(y[i])
        d = int(y[len(x) - 1 - i])
        acbd = a * c - b * d
        adbc = a * d - b * c
        bdac = b * d - a * c
        bcad = b * c - a * d
        possible = {"acbd": acbd, "adbc": adbc, "bdac": bdac, "bcad": bcad}
        possible = {a: possible[a] for a in possible if possible[a] >= 0}
        best = min(possible, key=possible.get)
        if best == "acbd":
            left[i] = str(a)
            right[i] = str(b)
            left[len(x) - 1 - i] = str(c)
            right[len(x) - 1 - i] = str(d)
        elif best == "adbc":
            left[i] = str(a)
            right[i] = str(b)
            left[len(x) - 1 - i] = str(d)
            right[len(x) - 1 - i] = str(c)
        elif best == "bdac":
            left[i] = str(b)
            right[i] = str(a)
            left[len(x) - 1 - i] = str(d)
            right[len(x) - 1 - i] = str(c)
        else:
            left[i] = str(b)
            right[i] = str(a)
            left[len(x) - 1 - i] = str(c)
            right[len(x) - 1 - i] = str(d)
    if len(x) % 2 != 0:
        a = int(x[len(x) // 2])
        b = int(y[len(x) // 2])
        if a > b:
            left[len(x) // 2] = str(a)
            right[len(x) // 2] = str(b)
        else:
            left[len(x) // 2] = str(b)
            right[len(x) // 2] = str(a)

    left = int("".join(left))
    right = int("".join(right))
    if left > right:
        ans.append(left)
        ans.append(right)
    else:
        ans.append(right)
        ans.append(left)
    t -= 1
for a in ans:
    print(a)
