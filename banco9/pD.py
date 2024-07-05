s = input()
tot = len(s) // 2
if len(s) % 2 == 1:
    for i in range(1, len(s)):
        if s[i] == "1":
            tot += 1
            break
print(tot)
