n = int(input())
nums = list(map(int, input().split()))

nums.sort()
max_spheres = (n - 1) // 2
right = nums[n - 1]
left = nums[max_spheres]
spheres = [left]
idx = 0
while len(spheres) < n - 1:
    spheres.append(nums[idx])
    idx += 1
    if len(spheres) < n - 1:
        spheres.append(nums[-idx - 1])
if len(spheres) < n:
    spheres.append(right)
print(max_spheres)
print(*spheres)
