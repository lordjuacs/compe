m, n = map(int, input().split())
alice = m + sum(list(map(int, input().split())))
bob = n + sum(list(map(int, input().split())))
print("ALICE" if alice > bob else "TIED" if alice == bob else "BOB")
