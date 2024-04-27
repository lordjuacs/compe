while True:
    n = int(input())
    if n == 0:
        break
    p1 = 0
    p2 = 0
    for i in range(n):
        op, m = input().split()
        m = int(m)

        if op == "DROP":
            p2 += m
            print(f"DROP 2 {m}")
        else:
            if p1 >= m:
                p1 -= m
                print(f"TAKE 1 {m}")
            else:
                if p1 > 0:
                    m -= p1
                    print(f"TAKE 1 {p1}")
                p1 = p2
                print(f"MOVE 2->1 {p2}")
                p2 = 0
                p1 -= m
                print(f"TAKE 1 {m}")
                
    print()