t = int(input())
i = 1
while t:
    n = int(input())
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))
    x.sort()
    y.sort(reverse=True)
    cart_sum = sum(a * b for a, b in zip(x, y))
    x.sort(reverse=True)
    y.sort()
    cart_sum = min(sum(a * b for a, b in zip(x, y)), cart_sum)
    print(f"Case #{i}: {cart_sum}")
    t -= 1
    i += 1
