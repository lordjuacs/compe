n = int(input())
for i in range(n):
    nums = input().split(" ")
    nums = [int(x) for x in nums]
    nums.sort()
    print(f"Case {i+1}: {nums[1]}")
