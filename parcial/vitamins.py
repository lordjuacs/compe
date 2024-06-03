INF = 1e6
n = int(input())
pA = INF
pB = INF
pC = INF
pAB = INF
pAC = INF
pBC = INF
pABC = INF

for i in range(n):
    ci, si = input().split()
    ci = int(ci)
    sortedsi = sorted(si)
    si = "".join(sorted(si))
    if si == "A":
        pA = min(pA, ci)
    elif si == "B":
        pB = min(pB, ci)
    elif si == "C":
        pC = min(pC, ci)
    elif si == "AB":
        pAB = min(pAB, ci)
    elif si == "AC":
        pAC = min(pAC, ci)
    elif si == "BC":
        pBC = min(pBC, ci)
    elif si == "ABC":
        pABC = min(pABC, ci)

tot_min = INF

if pA != INF and pB != INF and pC != INF:
    tot_min = min(tot_min, sum([pA, pB, pC]))

if pABC != INF:
    tot_min = min(tot_min, pABC)

if pA != INF and pBC != INF:
    tot_min = min(tot_min, pA + pBC)

if pB != INF and pAC != INF:
    tot_min = min(tot_min, pB + pAC)

if pC != INF and pAB != INF:
    tot_min = min(tot_min, pC + pAB)

if pAB != INF and pBC != INF:
    tot_min = min(tot_min, pAB + pBC)

if pAC != INF and pBC != INF:
    tot_min = min(tot_min, pAC + pBC)

if pAB != INF and pAC != INF:
    tot_min = min(tot_min, pAB + pAC)

if pAC != INF and pBC != INF:
    tot_min = min(tot_min, pAC + pBC)

if pAB != INF and pBC != INF:
    tot_min = min(tot_min, pAB + pBC)

print(-1 if tot_min == INF else tot_min)
