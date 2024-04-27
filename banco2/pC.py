n = int(input())
nums = list(map(int, input().split()))
gis = [nums[0]]
left_max = nums[0]
for i in range(1, n):
    if nums[i] > left_max:
        left_max = nums[i]
        gis.append(nums[i])
print(len(gis))
print(*gis)
