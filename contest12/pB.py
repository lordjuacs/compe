t = int(input())

while t:
    n = int(input())

    points = []

    r_input = list(map(float, input().split()))
    c_input = list(map(float, input().split()))
    for i in range(n):
        points.append((r_input[i], c_input[i]))

    points.sort(key=lambda x: x[0])
    points = [(1, 1)] + points
    min_cost = 0.0

    for i in range(1, n + 1):
        pi_diff = points[i][0] - points[i][1]
        pi1_diff = points[i - 1][0] - points[i - 1][1]
        if pi_diff == pi1_diff:
            if pi_diff % 2 == 0:
                min_cost += points[i][1] - points[i - 1][1]
        else:
            if pi1_diff % 2 == 0:
                min_cost += (pi_diff - pi1_diff) // 2
            else:
                min_cost += (pi_diff - pi1_diff + 1) // 2

    print(int(min_cost))
    t -= 1
