x1, y1, x2, y2 = map(int, input().split())
diff = y2 - y1
if diff % 2 == 0:
    a = (x2 - x1 + 1) * ((y2 - y1 + 2) // 2)
    b = (x2 - x1 + 1) // 2
    print(a - b)
else:
    a = (x2 - x1 + 1) * ((y2 - y1 + 1) // 2)
    print(a)
