n = int(input())
t = input().split(" ")
t = [float(i) for i in t]
count = sum(1 for i in t if i < 0)
print(count)