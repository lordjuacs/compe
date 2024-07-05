t = int(input())
while t:
    n, k = map(int, input().split())
    print("YES" if k * k <= n and n % 2 == k % 2 else "NO")
    t -= 1
