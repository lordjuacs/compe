# n = int(input())
# if (n - 2) % 2 == 0 and n >= 3:
for n in range(int(input())):
    if n % 2 == 0 and n >= 3:
        print(n, "YES")
    else:
        print(n, "NO")
