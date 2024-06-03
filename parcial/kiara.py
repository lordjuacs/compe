t = int(input())
while t:
    n = int(input())
    gl = input().split()
    glasses = []
    for i in range(n):
        glasses.append(int(gl[i]))
    seen = set()
    seen.add(glasses[0])
    flag = False
    for i in range(1, n):
        if i % 2:
            glasses[i] = glasses[i - 1] - glasses[i]
        else:
            glasses[i] += glasses[i - 1]
        if glasses[i] in seen or glasses[i] == 0:
            flag = True
            break
        seen.add(glasses[i])
    print("YES" if flag else "NO")
    t -= 1
