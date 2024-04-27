k = int(input())
momento = {}
matrix = []
for x in range(4):
    row = list(input())
    row = [int(i) if i.isdigit() else 0 for i in row]
    for i in row:
        if i in momento:
            momento[i] += 1
        else:
            momento[i] = 1
    matrix.append(row)
if 0 in momento:
    del momento[0]
flag = True
for i in momento:
    if momento[i] > 2 * k:
        print("NO")
        flag = False
        break
if flag:
    print("YES")
