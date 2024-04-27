n = int(input())
if n < 26:
    print("NO")
else:
    word = input()
    word = word.lower()
    word = set(word)
    if len(word) == 26:
        print("YES")
    else:
        print("NO")
