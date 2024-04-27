t = int(input())
for a in range(t):
    n = int(input())
    if n == 1:
        print("1")
    elif n % 2 != 0:
        print("-1")
    else:
        for i in range(2, n + 1, 2):
            print(str(i), end=" ")
            print(str(i - 1), end=" ")
        print()
