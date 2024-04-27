def check(a, b):
    digits = [0] * 10
    if a < 10000 or b < 10000:
        digits[0] += 1
    while a > 0:
        digits[a % 10] += 1
        a //= 10
    while b > 0:
        digits[b % 10] += 1
        b //= 10
    return all(x == 1 for x in digits)


ans = []
while True:
    n = int(input())
    if n == 0:
        break
    solved = False
    this = []
    for fghij in range(1234, 98766):
        abcde = fghij * n
        if abcde > 98765:
            break
        if check(abcde, fghij):
            solved = True
            this.append("{:05d} / {:05d} = {}".format(abcde, fghij, n))
    if not solved:
        this.append("There are no solutions for {}.".format(n))
    ans.append(this)
for a in range(len(ans)):
    for t in ans[a]:
        print(t)
    if a != len(ans) - 1:
        print()
