n = int(input())
zeros = 0
tot = 0
res = 0
nums = list(map(int, input().split()))
for num in nums:
    if num == 0:
        zeros += 1
    elif num > 0:
        res += num - 1
    else:
        res += -1 - num
        tot += 1
if tot % 2:
    if zeros:
        res += 1
        zeros -= 1
    else:
        res += 2
print(res + zeros)
