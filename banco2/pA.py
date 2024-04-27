while True:
    n = int(input())
    if n == 0:
        break
    bits =  [-1] * 32
    for i in range(n):
        ops = input().split()
        if ops[0] == "SET":
            bits[int(ops[1])] = 1
        elif ops[0] == "CLEAR":
            bits[int(ops[1])] = 0
        elif ops[0] == "OR":
            if bits[int(ops[1])] == 1 or bits[int(ops[2])] == 1:
                bits[int(ops[1])] = 1
            elif bits[int(ops[1])] == 0 and bits[int(ops[2])] == 0:
                bits[int(ops[1])] = 0
            else:
                bits[int(ops[1])] = -1
        elif ops[0] == "AND":
            if bits[int(ops[1])] == 1 and bits[int(ops[2])] == 1:
                bits[int(ops[1])] = 1
            elif bits[int(ops[1])] == 0 or bits[int(ops[2])] == 0:
                bits[int(ops[1])] = 0
            else:
                bits[int(ops[1])] = -1
    for i in range(31, -1, -1):
        if bits[i] == -1:
            print('?', end='')
        else:
            print(bits[i], end='')
    print()
