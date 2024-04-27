n = int(input())
nums = input().split(" ")
nums = [int(x) for x in nums]
nums.sort()

for i in range(len(nums)):
    if (i + 1) != nums[i]:
        print(i + 1)
        break
if nums[-1] != len(nums) + 1:
    print(len(nums) + 1)
