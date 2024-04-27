s = input()
pal = {}
for i in range(len(s)):
    if s[i] in pal:
        pal[s[i]] += 1
    else:
        pal[s[i]] = 1
odd = ""
valid = True
left = []
right = []
for i in pal:
    if pal[i] % 2 == 0:
        left += i * (pal[i] // 2)
        right += i * (pal[i] // 2)
    else:
        if odd != "":
            print("NO SOLUTION")
            valid = False
            break
        odd = i
        left += i * (pal[i] // 2)
        right += i * (pal[i] // 2)
if valid:
    print("".join(left) + odd + "".join(right[::-1]))
