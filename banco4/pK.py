n = int(input())
trees = list(map(int, input().split()))
day_grown = 0
trees.sort(reverse=True)
for i in range(1, n + 1):
    if trees[i - 1] + i > day_grown:
        day_grown = trees[i - 1] + i
print(day_grown + 1)
