def binary_search_left(arr, target, start):
    left, right = start, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid
    return left


t = int(input())
while t:
    n = int(input())
    array = list(map(int, input().split()))
    unique = list(sorted(set(array)))
    max_same = 0
    for i in range(len(unique)):
        target = unique[i]
        j = binary_search_left(unique, target + n, i)
        count = j - i
        max_same = max(max_same, count)
    print(max_same)
    t -= 1
