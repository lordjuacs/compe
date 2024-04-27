n = int(input())
all_valid = [i for i in range(1, 10)]
for k in range(2, n + 1):
    current_valid = []
    for num in all_valid:
        for digit in range(10):
            num_extra_digit = digit + num * 10
            if num_extra_digit % k == 0:
                current_valid.append(num_extra_digit)
    all_valid = current_valid
print(len(all_valid))
