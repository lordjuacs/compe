n = int(input())
nums = list(map(int, input().split()))
nums.sort(reverse=True)
a = 0
b = 0
for i in range(len(nums)):
    if i % 2 == 0:
        a += nums[i]
    else:
        b += nums[i]
print(f"{a} {b}")
