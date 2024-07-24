def update(pos, dif):
    global tree
    while pos < len(tree):
        tree[pos] += dif
        pos |= pos + 1


def lower_bound(sum):
    if sum <= 0:
        return -1
    pos = 0
    pw = 1 << 25
    while pw > 0:
        if pos + pw <= len(tree) and tree[pos + pw - 1] < sum:
            pos += pw
            sum -= tree[pos - 1]
        pw >>= 1
    return pos


n = int(input()) // 2
tree = [0] * 2 * n

for i in range(2 * n):
    update(i, 1)

first = list(map(int, input().split()))
second = list(map(int, input().split()))

first_choice = [0] * n
second_choice = [0] * n

for i in range(n):
    first_choice[i] = lower_bound(first[i])
    update(first_choice[i], -1)
    second_choice[i] = lower_bound(second[i])
    update(second_choice[i], -1)

print(" ".join(str(x + 1) for x in first_choice))
print(" ".join(str(x + 1) for x in second_choice))
