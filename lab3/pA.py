n = int(input())
while n:
    a, b, c = map(int, input().split())
    # cubic root of 10k = 21.54
    # square root of 10k/3 = 57.74
    # xyz = b --> z = b/xy --> x + y + z = a --> x + y + b/xy = a --> b/xy = a - x - y  --> x^2 + y^2 + z^2 = c --> x^2 + y^2 + (b/xy)^2 = c --> x^2 + y^2 + (a-x-y)^2 = c
    sol = False
    for i in range(-58, 58):
        for j in range(-58, 58):
            if i != j and ((i**2 + j**2 + (a - i - j) ** 2) == c):
                if i == 0 or j == 0:
                    continue
                k = b / (i * j)
                if i != k and j != k and i + j + k == a:
                    print(" ".join(str(int(a)) for a in sorted([i, j, k])))
                    sol = True
                    break
            if sol:
                break
        if sol:
            break
    if not sol:
        print("No solution.")
    n -= 1
