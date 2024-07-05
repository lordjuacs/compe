while True:
    n = int(input())
    if n == 0:
        break
    x = []
    y = []
    for _ in range(n):
        xi, yi = map(float, input().split())
        x.append(xi)
        y.append(yi)

    area = 0.0
    for i in range(n):
        area += x[i] * y[(i + 1) % n]
        area -= y[i] * x[(i + 1) % n]
    area = 0.5 * area

    if area < 0:
        print("CW", end=" ")
    else:
        print("CCW", end=" ")
    print(abs(area))
