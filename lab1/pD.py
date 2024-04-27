n = int(input())
kids = input().split()
kids = [int(i) for i in kids]
mapeo = {1: [], 2: [], 3: []}
for i in range(len(kids)):
    mapeo[kids[i]].append(i + 1)

maximo = min(len(mapeo[1]), len(mapeo[2]), len(mapeo[3]))
print(maximo)
if maximo != 0:
    for i in range(maximo):
        print(mapeo[1][i], mapeo[2][i], mapeo[3][i])
