nums = input().split(" ")
nums = [int(i) for i in nums]
cont = 0
while nums[0] <= nums[1]:
    nums[0] *= 3
    nums[1] *= 2
    cont += 1
print(cont)