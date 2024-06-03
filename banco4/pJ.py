t = int(input())
while t:
    n, k = map(int, input().split())
    array = list(map(int, input().split()))
    cost = 3001
    min_a = array[0]
    for d in range(1, min_a + 1):
        min_ai_pi = d
        max_ai_pi = -1
        for i in range(n):
            pi = min(array[i] // d, k)
            ai_pi = array[i] // pi
            max_ai_pi = max(ai_pi, max_ai_pi)
        cost = min(max_ai_pi - min_ai_pi, cost)
    print(cost)
    t -= 1
