n, m = list(map(int, input().strip().split()))
A = set(map(int, input().strip().split()))

i = 1
cur = []
out = []
while i <= n:
    cur.append(i)
    if i not in A:
        out.extend(cur[::-1])
        cur = []
    i += 1

print(" ".join(map(str, out)))
