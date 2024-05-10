# 4
# 01
# 1010101010111
# 00110001000
# 1
t = int(input())
while t:
    s = input()
    zeros = 1 if s[0] == "0" else 0
    ones = 1 if s[0] == "1" else 0
    max_del = 0
    for i in range(1, len(s)):
        # 00110001|000
        if s[i] == "0":
            zeros += 1
        else:
            ones += 1
        if zeros == ones:
            continue
        else:
            max_del = max(max_del, min(zeros, ones))
    print(max_del)
    t -= 1
