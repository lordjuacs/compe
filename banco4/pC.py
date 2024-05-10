import math

BITS = math.ceil(math.log2(2 * 10**5)) + 1
N = 2 * 10**5 + 1

bit_change = [[0] * N for _ in range(BITS)]

for i in range(BITS):
    for j in range(1, N):
        # print(f"n {j} bit {i}")
        bit_change[i][j] = bit_change[i][j - 1]
        if not ((j >> i) & 1):
            bit_change[i][j] += 1

t = int(input())
# print("BITS", BITS)
# print("N", N)
while t:
    l, r = map(int, input().split())
    min_change = (r - l) + 1
    for i in range(BITS):
        if bit_change[i][r] - bit_change[i][l - 1] < min_change:
            min_change = bit_change[i][r] - bit_change[i][l - 1]
    print(int(min_change))
    t -= 1
