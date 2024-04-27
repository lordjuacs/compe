reachable = {
    "1": "1234567890",
    "2": "2356890",
    "3": "369",
    "4": "4567890",
    "5": "56890",
    "6": "69",
    "7": "7890",
    "8": "890",
    "9": "9",
    "0": "0",
}
n = int(input())
for i in range(0, n):
    k = int(input())
    j = 0
    for j in range(200):
        tupper = str(k + j)
        tlower = str(k - j)
        upper = all(
            tupper[i + 1] in reachable[tupper[i]] for i in range(len(tupper) - 1)
        )
        lower = all(
            tlower[i + 1] in reachable[tlower[i]] for i in range(len(tlower) - 1)
        )
        if upper or lower:
            break
    print(k + j if upper else k - j)
