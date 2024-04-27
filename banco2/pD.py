n = int(input())
balloons = list(map(int, input().split()))
heights = [0] * (1000000)
arrows = 0
for b in balloons:
    if not heights[b + 1]:
        arrows += 1
    else:
        heights[b + 1] -= 1
    heights[b] += 1
print(arrows)
