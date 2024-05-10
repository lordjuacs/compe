t = int(input())
while t:
    n = int(input())
    balls = list(map(int, input().split()))
    max_balls = -1
    col = 0
    for i in range(len(balls)):
        if balls[i] > max_balls:
            max_balls = balls[i]
            col = i
    print(col + 1)
    t -= 1
