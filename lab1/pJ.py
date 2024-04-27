s = input()
m = int(input())
ans = [0] * len(s)
cont = 0
for i in range(1, len(s)):
    if s[i - 1] == s[i]:
        cont += 1
    ans[i] = cont
for i in range(m):
    l, r = input().split()
    print(ans[int(r) - 1] - ans[int(l) - 1])
