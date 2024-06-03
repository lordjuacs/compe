t = int(input())
while t:
    n = int(input())
    notas = list(map(int, input().split()))
    notas.sort(reverse=True)
    suma = 0
    for i in range(n):
        suma += notas[3 * i + 1]
    print(suma)
    t -= 1
