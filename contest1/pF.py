n = int(input())
values = input().split()
d = {}
for i in range(len(values)):
    d[chr(65 + i)] = True if values[i] == "T" else False

circuit = input()
curr = []
for i in range(len(circuit)):
    if circuit[i] == " ":
        continue
    if circuit[i] == "*":
        ans = curr[-1] and curr[-2]
        curr.pop()
        curr.pop()
        curr.append(ans)
    elif circuit[i] == "+":
        ans = curr[-1] or curr[-2]
        curr.pop()
        curr.pop()
        curr.append(ans)
    elif circuit[i] == "-":
        ans = not curr[-1]
        curr.pop()
        curr.append(ans)
    else:
        curr.append(d[circuit[i]])
print("T" if curr[-1] else "F")
