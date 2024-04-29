n = 30
for i in range(0, n + 1):
    mod = i % 3
    if mod == 0:
        print(i, mod, int(i / 3), 3 * int(i / 3))
    elif mod == 1:
        print(i, mod, int((i - 1) / 3), 3 * int((i - 1) / 3) + 1)
    else:
        print(i, mod, int((i - 2) / 3), 3 * int((i - 1) / 3) + 2)
