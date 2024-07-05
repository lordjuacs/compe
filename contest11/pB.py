def prefix(s):
    fi = [0] * len(s)
    j = 0
    for i in range(1, len(s)):
        while j > 0 and s[i] != s[j]:
            j = fi[j - 1]
        if s[i] == s[j]:
            j += 1
        fi[i] = j
    return fi


def count(s, f):
    comb = f + "-" + s
    pre = prefix(comb)
    return pre.count(len(f))


s = input()
f = input()
print(count(s, f))
