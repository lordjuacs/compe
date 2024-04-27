n = int(input())
total = list(range(1, 10))
for k in range(2, n + 1):
    ahora = []
    for numero in total:
        numero_extra = numero * 10
        while numero_extra % k != 0:
            numero_extra += 1
        for numero_extra_mas in range(numero_extra, (numero + 1) * 10, k):
            ahora.append(numero_extra_mas)
    total = ahora
print(len(total))
